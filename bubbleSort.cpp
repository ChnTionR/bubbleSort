#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <thread>

void swap(std::vector<int>& list, int pos1, int pos2){
    int temp = list[pos1];
    list[pos1] = list[pos2];
    list[pos2] = temp;
}


void shuffle(std::vector<int>& array){
    srand(time(NULL));
    for (int i = 0; i < array.size(); i++){
        swap(array, i, rand() % array.size());
    }
}


void draw(std::vector<int> array, int stepNo){
    for (int i = array.size(); i >= 1; i--){
        for (int element: array){
            if(element >= i){
                std::cout << "#" << "  ";
            }else{
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i < array.size(); i++){
        if(i == stepNo){
            std::cout<<"^  ^";
        }else{
            std::cout<<"   ";
        }
    }
}

void sort(std::vector<int>& array){
    int numSwap = '0';
    int cycleNum = 0;
    while(numSwap != 0){
        numSwap = 0;
        for (int i = 0; i < array.size() - cycleNum; i++){
            
            if(i+1 >= array.size()){
                break;
            }
            std::this_thread::sleep_for(std::chrono::microseconds(10));
            std::cout<<"\033[H";
            draw(array, i);

            if (array[i] > array[i+1]){
                swap(array, i, i+1);
                numSwap++;
            }
        }
        cycleNum++;
    }
}

int main(){
    std::vector<int> array;

    int size;
    system("clear");
    std::cin>>size;
    for(int i = 0; i < size; i++){
        array.push_back(i+1);
    }
    
    shuffle(array);
    sort(array);
    return 0;
}