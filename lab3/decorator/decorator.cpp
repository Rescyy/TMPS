#include <iostream>
using namespace std;

class SoftwareComponent {
    public:
        virtual ~SoftwareComponent() {}
        virtual void Operation() const = 0;
};

class Game : public SoftwareComponent {
    public:
        void Operation() const override {
            cout << "The game is running\n";
        }
};

class GameMod : public SoftwareComponent {

    protected:
        SoftwareComponent* software_component_;

    public:
        GameMod(SoftwareComponent* software_component) : software_component_(software_component) {
        }

        void Operation() const override {
            return software_component_->Operation();
        }
};

class FPSMod : public GameMod {

    public:
        FPSMod(SoftwareComponent* software_component) : GameMod(software_component) {
        }
        void Operation() const override {
            GameMod::Operation();
            cout << "FPS Count: 60 fps, 16.6 ms\n";
        }
};

class MoreContentMod : public GameMod {
    public:
        MoreContentMod(SoftwareComponent* software_component) : GameMod(software_component) {
        }

        void Operation() const override {
            GameMod::Operation();
            cout << "More Content Mod gameplay\n";
        }
};

void ClientCode(SoftwareComponent* software_component) {

    software_component->Operation();

}

int main() {

    SoftwareComponent* simple = new Game;
    ClientCode(simple);
    std::cout << "\n";

    SoftwareComponent* decorator1 = new FPSMod(simple);
    SoftwareComponent* decorator2 = new MoreContentMod(decorator1);
    ClientCode(decorator2);

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}