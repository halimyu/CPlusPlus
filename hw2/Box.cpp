//
// Created by halim on 9/12/2022.
//

class Box {

private:
    float width; // width of the box
    float depth; //  depth of the box
    float height; // height of the box

public:

    // Assigns default values of 1.0 to width, height, and depth unless a user enters otherwise
    explicit Box(float heightI = 1.0, float widthI = 1.0, float depthI = 1.0 ){
        // Check if the height entered is less than 0
        if (heightI < 0)
            heightI = 1.0;

        // Check if width entered is less than 0
        if (widthI < 0)
            widthI = 1.0;

        // Check if depth entered is less than 0
        if (depthI < 0)
            depthI = 1.0;

        height = heightI; // Assigning height entered to the height of the box
        width = widthI; // Assigning width entered to width of the box
        depth = depthI; // Assigning depth entered to depth of the box
    }

    // Change the value of width based on what the user enters, unless the value is less than 0 then it's 1.0
    void setWidth(float widthInput){
        if (widthInput < 0){
            widthInput = 1.0;
        }
        width = widthInput;
    }

    // Change the value of depth based on what the user enters, unless the value is less than 0 then it's 1.0
    void setDepth(float depthInput){
        if (depthInput < 0){
            depthInput = 1.0;
        }
        depth = depthInput;
    }

    // Change the value of height based on what the user enters, unless the value is less than 0 then it's 1.0
    void setHeight(float heightInput){
        if (heightInput < 0){
            heightInput = 1.0;
        }
        height = heightInput;
    }

    // returns the width of the box
    float getWidth(){
        return width;
    }

    // returns the depth of the box
    float getDepth(){
        return depth;
    }

    // returns the height of the box
    float getHeight(){
        return height;
    }

    // calculate and returns the volume of the box
    float getVolume(){
        return (width * height * depth);
    }

    // calculate and returns the surface area of the box
    float getSurfaceArea(){
        return 2 * (width * depth + height * depth + height * width);
    }

};
