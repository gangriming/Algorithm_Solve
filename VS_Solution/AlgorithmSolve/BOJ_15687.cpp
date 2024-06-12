#include <iostream>

using namespace std;

/*
생성자
    Rectangle(width, height): 직사각형의 가로 길이를 width, 세로 길이를 height 설정한다. width는 1,000보다 작거나 같은 자연수, height는 2,000보다 작거나 같은 자연수이다.
멤버 변수
    int width: 직사각형의 가로 길이
    int height: 직사각형의 세로 길이
멤버 함수
    int get_width() const: 직사각형의 가로 길이를 리턴한다.
    int get_height() const: 직사각형의 세로 길이를 리턴한다.
    void set_width(int width): 직사각형의 가로 길이를 width로 변경한다. 만약, width가 0보다 작거나 같거나, 1,000보다 크면 변경하지 않는다.
    void set_height(int height): 직사각형의 세로 길이를 height로 변경한다. 만약, height가 0보다 작거나 같거나, 2,000보다 크면 변경하지 않는다.
    int area() const: 직사각형의 넓이를 리턴한다.
    int perimeter() const: 직사각형의 둘레 길이를 리턴한다.
    bool is_square() const: 정사각형이면 true, 아니면 false를 리턴한다.
*/

class Rectangle {
private:
    int width, height;
public:
    Rectangle(int width, int height) 
    {
        this->width = width;
        this->height = height;
    }
    int get_width() const 
    {
        return width;
    }
    int get_height() const 
    {
        return height;
    }
    void set_width(int width) 
    {
        if (width <= 0 || width > 1000)
            return;
        this->width = width;
    }
    void set_height(int height) 
    {
        if (height <= 0 || height > 2000)
            return;
        this->height = height;
    }
    int area() const 
    {
        return width * height;
    }
    int perimeter() const 
    {
        return width * 2 + height * 2;
    }
    bool is_square() const 
    {
        return width == height;
    }
};