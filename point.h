//
// Created by abida on 23/03/2021.
//

#ifndef COBACOBATUBES_POINT_H
#define COBACOBATUBES_POINT_H


class point {
private:
    int x;
    int y;
public:
    point();
    point(int x, int y);
    ~point();
    point(const point & p);
    point& operator= (const point &p);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    void randomPoint(int maxX, int maxY);

    bool operator==(const point & p2);
};


#endif //COBACOBATUBES_POINT_H
