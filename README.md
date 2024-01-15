# Photoshop 

This an assignment for the Programming course where we developed an application that takes a photo (can take rgb image)and can create many functionalities such as:

1- Black & White Filter

​	Black and White Image If you apply this function to the loaded image, it will produce another  version of the image that is black and white. You can do this by calculating the average gray level for all pixels in the  image. And then every pixel above the average is turned to white (255)  and every pixel below average is turned to black (0).



2- Invert Filter

​	If you apply this function to the loaded image, it will produce the negative  of the image and you can store it in the file name you give. The negative has every black pixel turned to white and every white pixel  turned to black and every gray pixel is turned to opposite level of  brightness (255 – pixel value).



3- Merge Filter 

​	In this function, you will be asked to enter the name of another image.  Then the program will load this image. The program will create a new  image, with every pixel equal the average gray level of the corresponding  pixels in the images to merge.



4- Flip Image

​	This filter allows the user to flip the image  horizontally or vertically, as if it is reflected on a mirror.



5- Darken and Lighten Image 

​	This filter allows the user to make the image  darker or lighter by 50%.



6- Rotate Image

​	This filter allows the user  to rotate the image  clockwise by 90º, 180º or  270º as the user chooses.



7- Detect Image Edges 

​	This function finds the edges of the drawings in the image and turns the  image into a skeleton version of the original as if it is drawn with pencil  without coloring as shown.



8- Enlarge Image

​	This filter allows the user  to enlarge one of the four quarters of the image into  a separate new image.



9- Shrink Image

​	This filter allows the user  to shrink the image  dimensions to 1/2, 1/3 or  1/4 the original  dimensions.



10- Mirror 1/2 Image

​	This filter mirrors 1/2 of  the image as seen here in  order: Left 1/2, Right 1/2,  Upper 1/2 and Lower 1/2.



11- Shuffle Image

​	Assume the image  consist of 4 quarters as  shown, the user enters  the order he wants to the  quarters in the new  image. Wrong input is  rejected. Assume he  entered 4 3 2 1 he  gets image 1. Or if he enters 3 1 4 2 he gets image 2. User can enter any order he likes.



12- Blur Image

​	This filter produces a bury version of the image.



13- Save the image to a file

​	as you finish all filters you need to apply can save it as new image with new name.


to run the project : download the repo and then run main.cpp file as you run any cpp file in your environment
cmd 

```bash
// to compile the code run the next command
gcc main.cpp -o outputfile.exe
// to run the code
outputfile.exe
```

