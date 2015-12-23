#include <iostream>

int main(){
	char c;
	std::cin >> c;
	if((c >= 'a' && c <= 'z')){
		std::cout << "It work";
	}
	while(std::cin){
		std::cin >> c;
		if(c >= 'a' && c<= 'z'){
			std::cout << "it work many time";	
		}
	}
}
