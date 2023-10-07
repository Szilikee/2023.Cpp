#include <iostream>
#include <algorithm>
#include "Point.h"
#include "util.h"

using namespace std;

int main(int argc, char **argv) {

    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100, 200);
    Point p3(150, 360);
    Point p4(300, 400);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;
    delete pp1;
    delete pp2;

    cout << "\n\nFeladatok megoldasa\n\n";
    cout << "4.A pontok kozotti tavolsag: " << util::distance(p1, p2) << endl;
    if (util::isSquare(p1, p2, p3, p4)) {
        cout << "\n5.A pontok alkothatnak negyzetet." << endl;
    } else {
        cout << "\n5.A pontok nem alkothatnak negyzetet." << endl;
    }

    cout << "\n6. Negyzetet alkotnak-e a pontok" << endl;
    util util;
    util.testIsSquare("points.txt");

    cout << "\n7. Visszateriti a random szamok halmazanak cimet:" << endl;
    int size;
    cout << "Olvasd be hany random szamot szeretnel generalni: " << endl;
    cin >> size;
    Point *pontok = util.randomArray(size);
    for (int i = 0; i < size; ++i) {
        cout << "(" << pontok[i].getX() << "," << pontok[i].getY() << ")" << endl;
    }

    cout << "\n8. Kiirja a parameterul kapott pontokat tartalmazo tombot: " << endl; //A parameter ugyanaz lesz, amelyet az elozo feladatban megadtunk
    util.printArray(pontok, size);

    cout << " \n\n9. Legkozelebbi pontparok: " << endl;
    Point points[] = {
            {3, 4},
            {1, 2},
            {5, 6},
            {2, 1},
            {4, 3}
    };
    int numPoints = sizeof(points) / sizeof(points[0]);
    std::pair<Point, Point> closest = util::closestPoints(points, numPoints);
    std::cout << "Legkozelebbi pontparok: (" << closest.first.x << ", " << closest.first.y << ") es ("
              << closest.second.x << ", " << closest.second.y << ")" << std::endl;

    cout << "\n10. Legtavolabbi pontparok: " << endl;
    std::pair<Point, Point> farthest = util::farthestPoints(points, numPoints);
    std::cout << "Legmesszebb levo pontparok: (" << farthest.first.x << ", " << farthest.first.y << ") es ("
              << farthest.second.x << ", " << farthest.second.y << ")" << std::endl;

    cout << "\n11. Pontok rendezese: " << endl;
    util.sortPoints(points, numPoints);

    cout << "\n12. Origotol legtavolabbi pontparok: ";
    Point farthest2 = util.farthestPointFromOrigin(points, numPoints);
        std::cout <<  "(" << farthest2.x << ", " << farthest2.y << ")" << std::endl;

    util.deletePoints(pontok);

    cout<< "\n13. Pontok torlese megtortent." << endl;
    return 0;
}

