#include <iostream>
using namespace std;

class NetworkComponent;
class Mediator
{
public:
    virtual void Notify(string event) const = 0;
};

class NetworkComponent
{
protected:
    Mediator *mediator_;

public:
    NetworkComponent(Mediator *mediator = nullptr) : mediator_(mediator)
    {
    }
    void set_mediator(Mediator *mediator)
    {
        this->mediator_ = mediator;
    }
};

class Client : public NetworkComponent
{
public:
    void GetRequest()
    {
        std::cout << "Get Request sent to the server\n";
        this->mediator_->Notify("GET REQUEST");
    }
    void PostRequest()
    {
        std::cout << "Post Request sent to the server.\n";
        this->mediator_->Notify("POST REQUEST");
    }
};

class Server : public NetworkComponent
{
public:
    void GetResponse()
    {
        std::cout << "Server sent Get Response.\n";
        this->mediator_->Notify("GET RESPONSE");
    }
    void PostResponse()
    {
        std::cout << "Server sent Post Response.\n";
        this->mediator_->Notify("POST RESPONSE");
    }
};

/**
 * Concrete Mediators implement cooperative behavior by coordinating several
 * components.
 */
class ConcreteMediator : public Mediator
{
private:
    Server *server_;
    Client *client_;

public:
    ConcreteMediator(Server *server, Client *client) : server_(server), client_(client)
    {
        this->server_->set_mediator(this);
        this->client_->set_mediator(this);
    }
    void Notify(string event) const
    {
        if (event == "GET REQUEST")
        {
            std::cout << "Mediator reacts on Get Request and triggers following operations:\n";
            this->server_->GetResponse();
        }
        if (event == "POST REQUEST")
        {
            std::cout << "Mediator reacts on Post Request and triggers following operations:\n";
            this->server_->PostResponse();
            this->client_->GetRequest();
        }
    }
};

int main()
{
    Server *server = new Server();
    Client *client = new Client();
    ConcreteMediator *mediator = new ConcreteMediator(server, client);
    cout << "Client sends Get Request.\n";
    client->GetRequest();
    cout << "\n";
    cout << "Client sends Put Request.\n";
    client->PostRequest();
    return 0;
}