#include <iostream>
using namespace std;

class PC{
    private:
        string cpu;
        string gpu;
        string pc_case;
        string mouse;
        string keyboard;
        string headphones;
        int ram_memory_size;
        int hdd_memory_size;
        int ssd_memory_size;
        int monitors;
    public:
        void set_cpu(string _cpu){
            cpu = _cpu;
        }
        void set_gpu(string _gpu){
            gpu = _gpu;
        }
        void set_mouse(string _mouse){
            mouse = _mouse;
        }
        void set_keyboard(string _keyboard){
            keyboard = _keyboard;
        }
        void set_ram_memory_size(int _ram_memory_size){
            ram_memory_size = _ram_memory_size;
        }
        void set_hdd_memory_size(int _hdd_memory_size){
            hdd_memory_size = _hdd_memory_size;
        }
        void set_monitors(int _monitors){
            monitors = _monitors;
        }
        void inspect(){
            if(cpu != ""){
                cout << "CPU: " << cpu << endl;
            }
            if(gpu != ""){
                cout << "GPU: " << gpu << endl;
            }
            if(mouse != ""){
                cout << "Mouse: " << mouse << endl;
            }
            if(keyboard != ""){
                cout << "Keyboard: " << keyboard << endl;
            }
            if(ram_memory_size != 0){
                cout << "RAM: " << ram_memory_size << " GB" << endl;
            }
            if(hdd_memory_size != 0){
                cout << "HDD: " << hdd_memory_size << " GB" << endl;
            }  
            if(monitors != 0){
                cout << "Monitor Count: " << monitors << endl;
            }    
        }
};

class PCBuilder{
    private:
        PC result;
    public:
        void reset(){
            result.set_cpu("");
            result.set_gpu("");
            result.set_mouse("");
            result.set_keyboard("");
            result.set_ram_memory_size(0);
            result.set_hdd_memory_size(0);
            result.set_monitors(0);
        }
        void install_cpu(string _cpu){
            result.set_cpu(_cpu);
        }
        void install_gpu(string _gpu){
            result.set_gpu(_gpu);
        }
        void connect_mouse(string _mouse){
            result.set_mouse(_mouse);
        }
        void connect_keyboard(string _keyboard){
            result.set_keyboard(_keyboard);
        }
        void install_ram(int _ram){
            result.set_ram_memory_size(_ram);
        }
        void install_hdd(int _hdd){
            result.set_hdd_memory_size(_hdd);
        }
        void connect_monitors(int _monitors){
            result.set_monitors(_monitors);
        }
        PC getPC(){
            return result;
        }
};

class PCBuilderDirector{
    public:
        void buildGamingPC(PCBuilder *pcbuilder){
            pcbuilder->reset();
            pcbuilder->install_cpu("Intel i9_12900k");
            pcbuilder->install_gpu("Nvidia RTX 4070");
            pcbuilder->connect_mouse("Gaming Mouse");
            pcbuilder->connect_keyboard("RGB Mechanical Keyboard");
            pcbuilder->install_ram(64);
            pcbuilder->install_hdd(1024);
            pcbuilder->connect_monitors(3);
        }
        void buildWorkPC(PCBuilder *pcbuilder){
            pcbuilder->reset();
            pcbuilder->install_cpu("Intel i3_6100");
            pcbuilder->connect_keyboard("Membrane Keyboard");
            pcbuilder->install_ram(8);
            pcbuilder->install_hdd(256);
            pcbuilder->connect_monitors(1);
        }
        void buildAtari(PCBuilder *pcbuilder){
            pcbuilder->reset();
            pcbuilder->install_cpu("MOS6502");
        }
};