#include <iostream>
#include <queue>
#include <unistd.h>
using namespace std;


class Service {
    public:
        virtual void Request(string a) const = 0;
};

class PrintingService : public Service {
    public:
        void Request(string str) const override {
            cout << str;
        }
};

class PrintingProxy : public Service {
    private:
        PrintingService *printing_service_;
        int max_queue_members;
        queue<string> *qu = new queue<string>;

        bool CheckAccess() const {
            if(qu->size() >= max_queue_members){
                cout << "Proxy cannot take more printing requests.";
                return false;
            }
            return true;
        }

    public:
        PrintingProxy(PrintingService *real_subject) : printing_service_(new PrintingService(*real_subject)) {
        }
        void Cyclic() const {
            if(qu->size() != 0){
                string str = qu->front();
                qu->pop();
                printing_service_->Request(str);
            }
        }
        void Request(string a) const override {
            if (CheckAccess()) {
                qu->push(a);
            }
        }
};

void ClientCode(Service *subject, string str) {
    subject->Request(str);
}

int main() {
    PrintingService *ps = new PrintingService();
    PrintingProxy *pp = new PrintingProxy(ps);

    ClientCode(ps, "Hello!\n");
    ClientCode(ps, "I am blocking an adding program.\n");
    ClientCode(ps, "Still blocking it.\n");

    cout << "2 + 2 = 4\n";
    cout << "2 + 2 = 4\n";
    cout << "2 + 2 = 4\n";

    ClientCode(pp, "Hello!\n");
    ClientCode(pp, "I am not blocking it.\n");
    ClientCode(pp, "I am managing requests without complicating the client code and blocking other processes.\n");

    for(int i = 0; i < 5; i++){
        pp->Cyclic();
        cout << "2 + 2 = 4\n";
    }

    return 0;
}