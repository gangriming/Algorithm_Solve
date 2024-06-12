#include <iostream>

using namespace std;

/*
������
    Rectangle(width, height): ���簢���� ���� ���̸� width, ���� ���̸� height �����Ѵ�. width�� 1,000���� �۰ų� ���� �ڿ���, height�� 2,000���� �۰ų� ���� �ڿ����̴�.
��� ����
    int width: ���簢���� ���� ����
    int height: ���簢���� ���� ����
��� �Լ�
    int get_width() const: ���簢���� ���� ���̸� �����Ѵ�.
    int get_height() const: ���簢���� ���� ���̸� �����Ѵ�.
    void set_width(int width): ���簢���� ���� ���̸� width�� �����Ѵ�. ����, width�� 0���� �۰ų� ���ų�, 1,000���� ũ�� �������� �ʴ´�.
    void set_height(int height): ���簢���� ���� ���̸� height�� �����Ѵ�. ����, height�� 0���� �۰ų� ���ų�, 2,000���� ũ�� �������� �ʴ´�.
    int area() const: ���簢���� ���̸� �����Ѵ�.
    int perimeter() const: ���簢���� �ѷ� ���̸� �����Ѵ�.
    bool is_square() const: ���簢���̸� true, �ƴϸ� false�� �����Ѵ�.
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