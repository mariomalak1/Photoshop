// Program: photoshop.cpp
// Purpose: photoshop program use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and make some filters on it as user want and save it in new file
// Author:  Mario Malak - Mahmoud Sayed - Youssef Mohamed
// id:      20210313    - 2021          - 20210482
// Date:    15 April 2022
// Version: 2.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
// global array that take image in it
unsigned char image [SIZE][SIZE];
//------------------------------
// function that load image from user by it's name
void loadImage(unsigned char image [SIZE][SIZE]) {
    char imageFileName[100];
    cout << "please enter image name :";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
// ----------------------------
// function that save image
void saveImage(unsigned char image [][SIZE]) {
    char imageFileName[100];
    cout << "Enter the image file name after edit: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
    cout << "image saved" << endl;
}
// ---------------------------
// function to dark and light image
void dark_light(){
    int x;
    cout << "do you want to make the photo: \n" << "1-lighter\n" << "2-darker\n" << "0-to exit filter \n";
    cout << "what you want";
    cin >> x;
    if ((x == 1) or (x == 2)) {
        if (x == 1) {
            for (int i = 0; i < 255; i++) {
                for (int j = 0; j < 256; j++) {
                    image[i][j] += (256 - image[i][j]) / 2;
                }
            }
        }
        else if (x == 2) {
            for (int i = 0; i < 255; i++) {
                for (int j = 0; j < 256; j++) {
                    image[i][j] -= (image[i][j]) / 2;
                }
            }
        }
        cout << "end dark and light filter " << endl;
    }
    else if(x == 0){
        cout << "quit of filter ";
    }
    else{
        cout << "please enter valid response ";
        dark_light();
    }
}
// -----------------------------
// function rotate image
// function to take valid response from user
int response_rotate(){
    int degree = 0;
    cout << "Rotate (90), (180), (270) or (360) degrees ? , to quit from filter enter 0" << endl;
    while(true) {
        cout << "what degree you want to make the photo to it : " << endl;
        cin >> degree;
        if ((degree == 90) or (degree == 180) or (degree == 270) or (degree == 360)) {
            return degree;
        }
        else if(degree == 0){
            cout << "quit filter " << endl;
            return 0;
        }
        else {
            cout << "please enter valid degree" << endl;
            cin.ignore();
        }
    }
}
// function to make image rotate correctly
void rotate_image(){
    unsigned char image_rotated [SIZE][SIZE];
    int degree = 0;
    degree = response_rotate();
    if (degree != 0){
        if (degree == 90){
            for(int i = SIZE; i > 0; i--){
                for(int j = 0; j < SIZE; j++){
                    image_rotated[i][j] = image[j][i];
                }
            }
            for(int i = SIZE; i > 0; i--){
                for(int j = 0; j < SIZE; j++){
                    image[SIZE-i][j] = image_rotated[i][j];
                }
            }
        }
        else if (degree == 180) {
            for (int i = SIZE; i > 0; i--) {
                for (int j = 0; j < SIZE; j++) {
                    image_rotated[256 - i][j] = image[i][j];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE; j > 0; j--) {
                    image[i][SIZE-j] = image_rotated[i][j];
                }
            }
        }
        else if(degree == 270){
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    image_rotated[i][j] = image[j][i];
                }
            }
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    image[i][j] = image_rotated[i][SIZE-j];
                }
            }
        }
        cout << "end rotate filter " << endl;
    }
    else{
        cout << "quit of filter "<< endl;
    }
}
// ------------------------------
// function to invert photo
void Invert_Filter(){
    for (int i = 0; i <256; i++) {
        for (int j = 0; j< 256; j++) {
            image[i][j] = (255 - image[i][j]);
        }
    }
    cout << "end invert filter " << endl;
}
// ------------------------------
// function to make image balck and white
void BlackWhite() {
    unsigned char image[SIZE][SIZE];
    cout << "please enter image name to load it : ";
    long avg = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    cout << "end black and white filter" << endl;
}
// ---------------------------
// functions to flip image
// function to flip image vertical
void horizontal(){
    for (int i = 0 ; i < 256 ; ++i ) {
        for (int j = 0; j < 256 / 2; ++j){
            int ver = image[i] [j];
            image[i][j]  = image[i][255 - j];
            image[i][255 - j] = ver;
        }
    }
    cout << "end flip filter " << endl;
}
// function to flip image horizontal
void vertical(){
    for (int i = 0 ; i < 256 / 2 ; ++i ) {
        for (int j = 0; j < 256 ; ++j){
            int hor = image[i][j];
            image[i][j] = image[255 -i][ j];
            image[255 -i][j] = hor;
        }
    }
    cout << "end flip filter " << endl;
}
// function to adjust the flip in horizontal case or vertical case
void flip(){
    int mode;
    cout << "Choose flip mode: " << endl << "1 --> Vertical flip." << endl << "2 --> Horizontal flip." << endl << "0 --> exit filter" << endl;
    cin >> mode;
    if (mode == 1)
        vertical();
    else if (mode == 2)
        horizontal();
    else if(mode == 0){
        cout << "quit filter "<< endl;
    }
    else {
        cout << "Invalid input." << endl;
        flip();
    }
}
// ----------------------------
// function to make merge filter
void merge_filter(){
    cout << "we want to second image "<< endl;
    unsigned char image2 [SIZE][SIZE];
    loadImage(image2);
    unsigned char merge_image [SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            merge_image[i][j] = ((image[i][j] + image2[i][j])/2);
        }
    }
    for(int i = 0;i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image[i][j] = merge_image[i][j];
        }
    }
    cout << "end merge filter " << endl;
}
// ---------------------------
// function to Shrink image
string shrink_response(){
    string ratio;
    cout << "Shrink to (1/2), (1/3) or (1/4) ? write number as it writen without brackets, to quit from filter enter 0" << endl;
    while(true) {
        cout << "what ratio you want to shrink photo to it : " << endl;
        cin >> ratio;
        if ((ratio == "1/2") or (ratio == "1/3") or (ratio == "1/4")) {
            return ratio;
        }
        else if(ratio == "0"){
            cout << "end filter " << endl;
            return 0;
        }
        else {
            cout << "please enter valid degree" << endl;
            cin.ignore();
        }
    }
}
void Shrink(){
    string ratio = shrink_response();
    unsigned char shrink_image[SIZE][SIZE];
    if(ratio != "0"){
        // to make the shrink image array all have value 255 (white picture)
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrink_image[i][j] = 255;
            }
        }
        // to make shrink to half 1/2
        if(ratio == "1/2") {
            for (int i = 0; i < (SIZE/2); i++) {
                for (int j = 0; j < (SIZE/2); j++) {
                    shrink_image[i][j] = image[2 * i][2 * j];
                }
            }
        }
        else if(ratio == "1/3"){
            for (int i = 0; i < (SIZE/3); i++) {
                for (int j = 0; j < (SIZE/3); j++) {
                    shrink_image[i][j] = image[3 * i][3 * j];
                }
            }
        }
        else if(ratio == "1/4"){
            for (int i = 0; i < (SIZE /4); i++) {
                for (int j = 0; j < (SIZE /4); j++) {
                    shrink_image[i][j] = image[4 * i][4 * j];
                }
            }
        }
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                image[i][j] = shrink_image[i][j];
            }
        }
        cout << "end shrink filter " << endl;
    }
    else{
        cout << "quit of filter " << endl;
    }
}
// -------------------------------
// functions to make shuffle filter
string response_enlarge(){  // Show the quarter that the user wants to choose
    string response;

    while(true){
        cout<<" enter number from `(1,2,3,4)";
        cin>>response;
        if((response == "1") or (response == "2") or (response == "3") or (response == "4") ) {
            return response;
        }
        else{
            cout<<"enter corrected number"<<endl;
        }
    }
}
void enlarge() {
    unsigned char small_image[128][128];
    string choose = response_enlarge();
    if(choose == "1"){ //First Quarter
        for (int i = 0; i <= 128; i++) {
            for (int j = 0; j <= 128; j++) {
                small_image[i][j] = image[i][j];

            }
        }
    }
    else if (choose == "2"){  //second Quarter
        for (int i = 128; i < 256; i++) {
            for (int j = 128; j < 256; j++) {
                small_image[i-128][j-128] = image[i][j];
            }
        }
    }
    else if (choose == "3"){ //third quarter
        for (int i = 128; i <256 ; i++) {
            for (int j = 0; j < 128; j++) {
                small_image[i-128][j] = image[i][j];
            }
        }
    }
    else if (choose == "4"){        //Fourth quarter
        for (int i = 128; i <256 ; i++) {
            for (int j = 128; j < 256; j++) {
                small_image[i-128][j-128] = image[i][j];
            }
        }
    }
    for(int i = 0, x = 0; i <= 256, x <= 128; i += 2, x++)
    {
        for(int j = 0, y = 0; j <= 256, y <= 128; j += 2 ,y++)
        {
            image[i][j] = small_image[x][y];
            image[i+1][j] = small_image[x][y];
            image[i][j+1] = small_image[x][y];
            image[i+1][j+1] = small_image[x][y];
        }
    }
}
// -------------------------------
// function to blur the image
// function to get blur degree
int blur_degree(int i, int j , unsigned char image[SIZE][SIZE] ,int blur_point = 0){
//    blur_point = ;
    blur_point = ((( image[i-1][j-1] ) + ( image[i-1][j] ) + ( image[i-1][j+1] ) + ( image[i][j-1] ) + ( image[i][j] ) + ( image[i][j+1] ) + ( image[i+1][j-1] ) + ( image[i+1][j]) + ( image[i+1][j+1] ) ) + ((image[i-2][j-2]) + (image[i-2][j-1]) + (image[i-2][j]) + (image[i-2][j+1]) + (image[i-2][j+2]) + (image[i-1][j-2]) + (image[i][j-2]) + (image[i+1][j-2]) + (image[i+2][j-2]) + (image[i+2][j-1]) + (image[i+2][j]) + (image[i+2][j+1]) + (image[i+2][j+2]) + (image[i+1][j+2]) + (image[i][j+2]) +(image[i-1][j+2]))) / 25;
    return blur_point;
}
// function to make image blur correctly
void blur(){
    unsigned char blur_image[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if (((i >= 2) and (j >= 2)) or ((i <= 255) and (i <= 255))){
                blur_image[i][j] = blur_degree(i,j , image);
            }
            else{
                blur_image[i][j] = image[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; ++j){
            image[i][j] = blur_image[i][j];
        }
    }
    cout << "end the blur filter "<< endl;
}
// -------------------------------
// function to detect edges of image
void detect_edges(){
    long avg = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            avg += image[i][j]; // taking the sum of all elements in the photo
        }
    }
    avg /= (SIZE * SIZE); // to calculate the average color of the photo
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if ( ( image[i][j] < avg ) and ( image[i][j+1] < avg ) ){
                while ( image[i][j+4] < avg){
                    if (image[i+1][j]<avg){
                        // if there is a black cell and black cells after it , makes these two cells white
                        image[i][j+2]=255;
                        j+=1;
                    }
                    else{
                        j+=1;
                    }
                }
            }
            if (image[i][j]>avg){
                image[i][j] = 255; // if cell is more than average color of photo make it white
            }
        }
    }
    cout << "end filter" << endl;
}
// ----------------------------
// function to make mirror
void left() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image [i][j] = image[255-i][j] ;

        }
    }
}
void Right() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image [i][j] = image[i][255-j] ;

        }
    }
}
void Upper() {
    for (int i = SIZE ; i >=0; i--) {
        for (int j = SIZE ; j>= 0; j--) {
            image [i][j] = image[255-i][j] ;

        }
    }
}
void Lower() {
    for (int i = SIZE ; i >=0; i--) {
        for (int j = SIZE ; j>= 0; j--) {
            image [i][j] = image[i][255-j] ;

        }
    }
}
void mirror() {
    int n ;
    cout << "1--> For left half mirror." << "\n" <<  "2-- > For right half mirror." <<"\n" << "3--> For upper half mirror."
         << "\n" <<  "4--> For lower half mirror."  << "\n"  << "0--> TO End The Filter. \n";
    cin >> n ;
    if (n == 1) {
        left();
        cout << "end of the filter" << endl;
    }
    else if (n==2) {
        Right();
        cout << "end of the filter" << endl;
    }
    else if (n==3) {
        Upper();
        cout << "end of the filter" << endl;
    }
    else if(n==4) {
        Lower();
        cout << "end of the filter" << endl;
    }
    else if (n==0)
        cout << "Quit filter" << endl;
}
// ----------------------------
// functions to make shuffle filter
void find_coordinates2(int choice, int &i, int &repeatedj ,int &row, int &colunm)
{
    //this function to take the number of the photo quarter that the user wanted and makes the variables take the start and last of the quarter from row and colunm
    switch(choice)
    {
        case 1: i = 0; repeatedj = 0; row= (SIZE / 2) ; colunm = (SIZE / 2) ;
            break;
        case 2: i = 0 ; repeatedj = (SIZE/2) ; row = (SIZE/2) ; colunm= SIZE ;
            break;
        case 3: i = (SIZE / 2);repeatedj=0;row=SIZE;colunm= (SIZE / 2);
            break;
        case 4: i = (SIZE / 2); repeatedj = (SIZE / 2) ; row = SIZE ; colunm = SIZE;
            break;
    }
}
void find_coordinates1(int choice, int k, char image4[SIZE][SIZE])
{
    int i,j,repeatedj,row,colunm,x,y,repeatedy;
    find_coordinates2(choice,i,repeatedj,row,colunm);
    //this switch to take the number of the quarter of the array that we wanted to fill it by photo pixels and make the variable take the start and last of row and column of quarter
    switch(k)
    {
        case 1:x=0;repeatedy=0;
            break;
        case 2:x=0;repeatedy=SIZE/2;
            break;
        case 3:x=SIZE/2;repeatedy=0;
            break;
        case 4:x=SIZE/2;repeatedy=SIZE/2;
            break;
    }
    //this for loop to fill the image by pixels in the array again
    for(;i<row;i++,x++){
        for(j=repeatedj,y=repeatedy;j<colunm;j++,y++){
            image[x][y] = image4[i][j];
        }
    }

}
void Shuffle_Image()
{

    char image4[SIZE][SIZE];
    int choice;
    //this for loops to fill the array by the pixels of the image to make second copy of it
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image4[i][j] = image[i][j];
        }
    }
    cout<<"what is New order of quarters you want to be?"<<endl;
    for(int k=1;k<=4;k++){
        cin >> choice;
        find_coordinates1(choice, k, image4);
    }
}
// ----------------------------
// function to display menu
void menu(){
    cout << "It's menu of the Photoshop program "<< endl;
    cout << "Please select a filter to apply or 0 to exit:"<< endl;
    cout << "   1- Black & White Filter" <<endl;
    cout << "   2- Invert Filter" <<endl;
    cout << "   3- Merge Filter" <<endl;
    cout << "   4- Flip Image" <<endl;
    cout << "   5- Darken and Lighten Image" <<endl;
    cout << "   6- Rotate Image" <<endl;
    cout << "   7- Detect Image Edges" <<endl;
    cout << "   8- Enlarge Image" <<endl;
    cout << "   9- Shrink Image" <<endl;
    cout << "   a- Mirror 1/2 Image" <<endl;
    cout << "   b- Shuffle Image" <<endl;
    cout << "   c- Blur Image" <<endl;
    cout << "   s- Save the image to a file" <<endl;
    cout << "   0- Exit" <<endl;
}
//------------------------------
// function to take valid response
void take_response(){
    loadImage(image);
    string response;
    while (true){
        cout << "what filter you want: ";
        cin >> response;
        if (response == "0"){
            cout << "End of the program " << endl;
            break;
        }
        else if(response == "1"){
            BlackWhite();
        }
        else if(response == "2"){
            Invert_Filter();
        }
        else if(response == "3"){
            merge_filter();
        }
        else if(response == "4"){
            flip();
        }
        else if(response == "5"){
            dark_light();
        }
        else if(response == "6"){
            rotate_image();
        }
        else if(response == "7"){
            detect_edges();
        }
        else if(response == "8"){
            enlarge();
        }
        else if(response == "9"){
            Shrink();
        }
        else if(response == "a"){
            mirror();
        }
        else if(response == "b"){
            Shuffle_Image();
        }
        else if(response == "c"){
            blur();
        }
        else if(response == "s"){
            saveImage(image);
        }
        else{
            cout << " please enter valid response "<< endl;
        }
    }
}
int main(){
    menu();
    take_response();
    return 0;
}

