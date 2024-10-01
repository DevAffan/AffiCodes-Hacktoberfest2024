using System;

class Program
{
    static void Main()
    {
        // Square Perimeter
        int squareSideLength = 55; 
        int squarePerimeter = 4 * squareSideLength;

        Console.WriteLine($"Perimeter of the square: {squarePerimeter}");

        // Triangle Perimeter
        int triangleSideX = 9; 
        int triangleSideY = 16;
        int triangleSideZ = 24;

        int trianglePerimeter = triangleSideX + triangleSideY + triangleSideZ;

        Console.WriteLine($"Perimeter of the triangle: {trianglePerimeter}");
        Console.ReadLine();
    }
}

