using System;
using LV5.LinearAlgebra;
using LV5.LinearAlgebra.Operations;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LV5.Test
{
    internal class Tester
    {
        public static void Run() 
        {
            Vector a = new Vector();
            Vector b = new Vector(1, 2, 3);
            Vector c = new Vector(2, 4, 6);
            Vector d = new Vector(7, 11, 13);
            Vector[] vectors = new Vector[] { a, b, c, d };

            foreach (Vector vector in vectors)
            {
                Console.WriteLine($"Vector: {vector}");
                Console.WriteLine($"\tIs null vector? : {vector.IsNullVector()}");
                Console.WriteLine($"\tEuclidean norm: {vector.CalculateEuclideanNorm()}");
            }

            Console.WriteLine($"Angle between {c} and {d} is {VectorMath.CalculateAngleBetween(c, d)} degrees.");
            Console.WriteLine($"Dot product of {c} and {d} is {VectorMath.CalculateDotProduct(c, d)}.");
            Console.WriteLine($"Cross product of {c} and {d} is {VectorMath.CalculateCrossProduct(c, d)}.");

            double delta = 0.001;
            Assert.AreEqual(136, VectorMath.CalculateDotProduct(c, d));
            Assert.AreEqual(9.2261, VectorMath.CalculateAngleBetween(c, d), delta);
            Assert.AreEqual(0.0000, VectorMath.CalculateAngleBetween(b, c), delta);

            Assert.IsTrue(VectorMath.CalculateCrossProduct(b, c).IsNullVector());
            Assert.IsFalse(VectorMath.CalculateCrossProduct(b, d).IsNullVector());

            Assert.IsTrue(VectorMath.AreColinear(b, c));
            Assert.IsFalse(VectorMath.AreColinear(b, d));

            Console.WriteLine("After multiplication:");

            int scalar = 3;
            foreach (Vector vector in vectors)
            {
                vector.MultiplyBy(scalar);
                Console.WriteLine($"Vector: {vector}");
            }
        }
    }
}
