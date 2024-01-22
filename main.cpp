#include <iostream>


std::string crypt (std::string cryptMess, int keyCpypt ) {
  if(keyCpypt >26 || keyCpypt< 26){
      keyCpypt = keyCpypt%26;
  }

      if(keyCpypt >= 0) {
          for (int i = 0; i <= cryptMess.length(); ++i) {
              if (cryptMess[i] >= 'a' && cryptMess[i] <= 'z' - keyCpypt ||
                  cryptMess[i] >= 'A' && cryptMess[i] <= 'Z' - keyCpypt) {
                  cryptMess[i] += keyCpypt;
              } else if (cryptMess[i] >= 'z' - keyCpypt && cryptMess[i] <= 'z' ||
                         cryptMess[i] >= 'Z' - keyCpypt && cryptMess[i] <= 'Z') {
                  cryptMess[i] = cryptMess[i] + keyCpypt -26;
              }
          }
      }else if(keyCpypt< 0){
          for(int i = 0; i<= cryptMess.length(); ++i){
              if(cryptMess[i] >= 'a' - keyCpypt && cryptMess[i] <= 'z'|| cryptMess[i]>= 'A'- keyCpypt && cryptMess[i]<= 'Z'){
                  cryptMess[i] += keyCpypt;
              }else
                  if(cryptMess[i]<= 'a' - keyCpypt && cryptMess[i]>='a'||cryptMess[i]<= 'A' - keyCpypt && cryptMess[i]>= 'A' ){
                  cryptMess[i] =   cryptMess[i] + keyCpypt  + 26;
              }
          }
      }
  return(cryptMess) ; 
}
std::string decrypt(std::string decryptMess, int keyDecpypt){
  for (int i=0;i<= decryptMess.length(); i++ ){

    decryptMess[i] = crypt(decryptMess, -keyDecpypt)[i];
  }
  return(decryptMess);
}
int main() {
  std::string message;
  std::cout << "Enter message to nesesery crypt: \n";
  std::getline(std::cin, message);

  std::cout <<"Enter cpypt key \n";
  int keyNumber;
  std::cin>> keyNumber;
  message = crypt(message, keyNumber) ;
  std::cout << message << std::endl;
  std::cout<<"You want decrypt message? Y/N\n";
  std::string answer;
  std::cin >> answer;
  
  if(answer == "Y"|| "y"){
     message = decrypt(message, keyNumber);
     std::cout << message;
  }

}