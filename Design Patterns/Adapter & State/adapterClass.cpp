// figures: class adapter pattern 
//Elijah Rogers

#include <iostream>

using std::cout; using std::endl; using std::cin;

// target interface
class Square {
public:
   virtual void draw() const =0;
   virtual void resize(int) =0;
   virtual ~Square(){}
};

// adaptee/implementer
class LegacyRectangle{
public:
   LegacyRectangle(int topLeftX, 
		   int topLeftY, 
		   int bottomRightX, 
		   int bottomRightY): topLeftX_(topLeftX), topLeftY_(topLeftY), bottomRightX_(bottomRightX), bottomRightY_(bottomRightY){}
      void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY){ //implements generic repositioning and resizing of the figure;
         topLeftX_ = topLeftX; 
         topLeftY_ = topLeftY; 
         bottomRightX_ = bottomRightX; 
         bottomRightY_ = bottomRightY;
      }
      //return the respective corner coordinates.
      int getTopLeftX() const{return topLeftX_;}
      int getTopLeftY() const{return topLeftY_;}
      int getBottomRightX() const{return bottomRightX_;}
      int getBottomRightY() const{return bottomRightY_;}

   void oldDraw() const {
      for(int i=0; i < bottomRightY_; ++i){
         for(int j=0; j < bottomRightX_; ++j)
            if(i >= topLeftY_  && j >= topLeftX_ )
               cout << '*';
            else
               cout << ' ';
         cout << endl;
            }
   }
// defining top/left and bottom/right coordinates 
private: 
   int topLeftX_;
   int topLeftY_;
   int bottomRightX_;
   int bottomRightY_;
};

// int size() returns the current square size;
// void resize(int newSize) changes the size of the figure by moving its bottom right corner.
// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter: public Square, 
		     private LegacyRectangle {
public:
   SquareAdapter(int size): LegacyRectangle(0,0,size,size){};
   void draw() const override {
      oldDraw();
   }
   int size(){
      int size = getBottomRightX();
      return size;
   }
   void resize(int newSize) override {
      move(0,0,newSize,newSize);
   }
};


// Demonstrate this functionality by coding main() as follows: ask the user for the size of a square, declare a square of the user-specified size, 
// draw the square; then ask the user for a new size, resize the square to the new size and redraw it.
//------------------------------------------
int main(){
   int size;
   cout << "Gimme a square size peasant: ";
   cin >> size;
   Square *square = new SquareAdapter(size);
   square->draw();
   cout << "------------------------------------------------------------------------------" << endl;
   cout << "Gimme a new square size peasant -- your old one sucked: ";
   cin >> size;
   square->resize(size);
   square->draw();
}
