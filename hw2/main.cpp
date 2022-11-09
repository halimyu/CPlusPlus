#include <iostream>
#include "Box.cpp"

using namespace std;

int main() {

    // Constructor tests:
    Box box = Box();
    Box box1 = Box(13.3, 5.8, 1.5);
    Box box2 = Box(5.0, 10.0, 12.0);
    Box box3 = Box(-10.0, -9.0, -60.0);

    // getDepth method tests
    cout << "getDepth Tests: " <<endl;
    cout << "Expected box.getDepth() to return 1. Actual is " << box.getDepth() << endl;
    cout << "Expected box1.getDepth() to return 1.5. Actual is " << box1.getDepth() << endl;
    cout << "Expected box2.getDepth() to return 12. Actual is " << box2.getDepth() << endl;
    cout << "Expected box3.getDepth() to return 1. Actual is " << box3.getDepth() << endl;

    // getHeight method test
    cout << endl;
    cout << "getHeight Tests: " << endl;
    cout << "Expected box.getHeight() to return 1. Actual is " << box.getHeight() << endl;
    cout << "Expected box1.getHeight() to return 13.3. Actual is " << box1.getHeight() << endl;
    cout << "Expected box2.getHeight() to return 5. Actual is " << box2.getHeight() << endl;
    cout << "Expected box3.getHeight() to return 1. Actual is " << box3.getHeight() << endl;

    // getWidth method test
    cout << endl;
    cout << "getWidth Tests: " << endl;
    cout << "Expected box.getWidth() to return 1. Actual is " << box.getWidth() << endl;
    cout << "Expected box1.getWidth() to return 5.8. Actual is " << box1.getWidth() << endl;
    cout << "Expected box2.getWidth() to return 10. Actual is " << box2.getWidth() << endl;
    cout << "Expected box3.getWidth() to return 1. Actual is " << box3.getWidth() << endl;

    // setHeight Tests:
    cout << endl;
    cout << "setHeight Tests: " << endl;
    box.setHeight(5.0);
    cout << "Expected box.setHeight to set height to 5.0 and box.getHeight to return 5. Actual is " <<
         box.getHeight() << endl;
    box1.setHeight(0.0);
    cout << "Expected box1.setHeight to set height to 0.0 and box1.getHeight to return 0. Actual is " <<
         box1.getHeight() << endl;
    box2.setHeight(-13.0);
    cout << "Expected box2.setHeight to set height to 1.0 and box2.getHeight to return 1. Actual is " <<
         box2.getHeight() << endl;
    box3.setHeight(10.0);
    cout << "Expected box3.setHeight to set height to 10.0 and box3.getHeight to return 10. Actual is " <<
         box3.getHeight() << endl;


    // setWidth Tests:
    cout << endl;
    cout << "setWidth Tests: " << endl;
    box.setWidth(-9.0);
    cout << "Expected box.setWidth to set width to 1.0 and box.getWidth to return 1. Actual is " <<
         box.getWidth() << endl;
    box1.setWidth(16.5);
    cout << "Expected box1.setWidth to set width to 16.5 and box1.getWidth to return 16.5. Actual is " <<
         box1.getWidth() << endl;
    box2.setWidth(0.0);
    cout << "Expected box2.setWidth to set width to 0.0 and box2.getWidth to return 0. Actual is " <<
         box2.getWidth() << endl;
    box3.setWidth(2.3);
    cout << "Expected box3.setWidth to set width to 2.3 and box3.getWidth to return 2.3. Actual is " <<
         box3.getWidth() << endl;


    // setDepth Tests:
    cout << endl;
    cout << "setDepth Tests: " << endl;
    box.setDepth(5.2);
    cout << "Expected box.setDepth to set depth to 5.2 and box.getDepth to return 5.2. Actual is " <<
         box.getDepth() << endl;
    box1.setDepth(-15.3);
    cout << "Expected box1.setDepth to set depth to 1.0 and box1.getDepth to return 1.0. Actual is " <<
         box1.getDepth() << endl;
    box2.setDepth(15.8);
    cout << "Expected box2.setDepth to set depth to 15.8 and box2.getDepth to return 15.8. Actual is " <<
         box2.getDepth() << endl;
    box3.setDepth(0.0);
    cout << "Expected box3.setDepth to set depth to 0.0 and box3.getDepth to return 0. Actual is " <<
         box3.getDepth() << endl;



    // getVolume Tests:
    cout << endl;
    cout << "getVolume Tests: " << endl;
    cout << "Expected box.getVolume() to return 26. Actual is " << box.getVolume() << endl;
    cout << "Expected box1.getVolume() to return 0. Actual is " << box1.getVolume() << endl;
    cout << "Expected box2.getVolume() to return 0. Actual is " << box2.getVolume() << endl;
    cout << "Expected box3.getVolume() to return 0. Actual is " << box3.getVolume() << endl;

    // getSurfaceArea Tests:
    cout << endl;
    cout << "getSurfaceArea Tests: " << endl;
    cout << "Expected box.getSurfaceArea() to return 72.4. Actual is " << box.getSurfaceArea() << endl;
    cout << "Expected box1.getSurfaceArea() to return 33. Actual is " << box1.getSurfaceArea() << endl;
    cout << "Expected box2.getSurfaceArea() to return 31.6. Actual is " << box2.getSurfaceArea() << endl;
    cout << "Expected box3.getSurfaceArea() to return 46. Actual is " << box3.getSurfaceArea() << endl;



    return 0;
}
