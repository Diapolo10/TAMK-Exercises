/*
 * Hardware - SKIDBLADNIR MK2:
 * - 4x8GB DDR4 @ 3200 MHz
 * - Intel Core i9-9900k (8c/16t) @ 5.0 GHz all-core OC
 * - MSVC version 19.23.28105.4
 * - Windows 10 version 1909 build 18363.535

 * Seuraavan kokoisia paikallisia taulukoita onnistui varata: 1024 kilotavua, 2048 kilotavua, ..., 65536 kilotavua. 
 * Tilavaraus epäonnistui ensimmäisen kerran seuraavaan kokoon: 65,537 kilotavua
 *
 * Dynaamisen muistin alueelta onnistui tilavaraukset: 1 tavu - 17 gigatavua (=8*2^n bittiä, n = [0, 36])
 * Tilavaraus dyn.muistin alueelta epäonnistui 1. kerran seuraavalla koolla: 34 359 738 368 tavua
 */

/*
 * DISCLAIMER: The author of this code takes no responsibility for anything the program may cause on one's system when run.
 * The dynamic memory allocation ended up freezing the author's computer at 100% memory allocation, because nothing was left for the system.
 * Due to this, there's an additional header guard that disables that part of the code.
 */


#include <iostream>

#define TYPE char
//#define __DYNAMIC__


const size_t TYPE_SIZE{ sizeof(TYPE) * CHAR_BIT };

int main() {

    const size_t current_static_size{ TYPE_SIZE * 65536 };
    TYPE bar[current_static_size];
    


    #ifdef __DYNAMIC__
    // Dynamic allocation - WARNING, MAY FREEZE THE COMPUTER, RUN AT YOUR OWN RISK.
    size_t current_size = TYPE_SIZE;
    while (true) {

        TYPE* foo{};
    
        try {
            foo = new TYPE[current_size];
            std::cout << current_size << " worked.\n";
        }
        catch (std::bad_alloc) {
            std::cerr << "Could not allocate " << current_size << " bits of memory.\n";
            delete[] foo;
            break;
        }
        

        delete[] foo;
        current_size *= 2;
    }
    #endif // __DYNAMIC__
}