#include <iostream>
#include <string>

class Book{
  private:
    // char title[20];
    std::string title;
    int price;
    int page;
  public:
    Book(std::string _title, int _price, int _page)
    :title(_title), price(_price), page(_page){      
    }
    void Input(void){
      std::cout<<"[input()]\n";
      std::cout<<"title: ";std::cin>>title;
      std::cout<<"price: ";std::cin>>price;
      std::cout<<"page : ";std::cin>>page;
    }
    void Output(void){
      std::cout<<"[output()]\n";
      std::cout<<"title: "<<title<< std::endl;
      std::cout<<"price: "<< price<< std::endl;
      std::cout<<"page : "<< page<< std::endl;
    }
};

int main(void){
  Book book("1st book", 7500, 290);
  book.Output();

  void (Book::* Inputbook)(void) = &Book::Input;
  (book.*Inputbook)();
  book.Output();
}

