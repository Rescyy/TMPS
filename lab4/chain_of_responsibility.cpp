#include <iostream>
using namespace std;

typedef struct{
    int id;
    string payload;
}message;

class Handler{
    public:
        virtual Handler *setNext(Handler *handler) = 0;
        virtual void Handle(message *request) = 0; 
};

class AbstractHandler : public Handler{
    protected:
        Handler *next_handler_;
        int id;
    public:
        AbstractHandler() : next_handler_(nullptr){

        }
        void setId(int id_){
            this->id = id_;
        }
        Handler *setNext(Handler *handler) override {
            this->next_handler_ = handler;
            return handler;
        }
        void Handle(message *request) override {
            if (this->next_handler_ != nullptr){
                this->next_handler_->Handle(request);
            }
        }
};

class RequestHandler1 : public AbstractHandler{
    public:
        void Handle(message *request) override{
            if(request->id == this->id){
                cout << "Message received by handler " << this->id << "\n";
                cout << "Payload: " << request->payload << "\n\n";
            }
            else{
                AbstractHandler::Handle(request);
            }
        }
};

class RequestHandler2 : public AbstractHandler{
    public:
        void Handle(message *request) override{
            if(request->id == this->id){
                cout << "Message received by special handler " << this->id << "\n\n";
            }
            else{
                AbstractHandler::Handle(request);
            }
        }
};

int main(){
    RequestHandler1 *handler1 = new RequestHandler1;
    RequestHandler1 *handler2 = new RequestHandler1;
    RequestHandler2 *handler3 = new RequestHandler2;
    handler1->setId(11);
    handler2->setId(12);
    handler3->setId(13);
    handler1->setNext(handler2)->setNext(handler3);
    message mes1 = {0, "Send to handler1"};
    handler1->Handle(&mes1);
    mes1.id = 11;
    handler1->Handle(&mes1);
    message mes2 = {11, "Send to handler3"};
    handler3->Handle(&mes2);
    mes2.id = 13;
    handler3->Handle(&mes2);
    return 0;
}
