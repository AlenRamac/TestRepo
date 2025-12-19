using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LV5.LinearAlgebra.Operations
{
    public static class VectorMath
    {
        public static double CalculateDotProduct(Vector a, Vector b)
        {
            return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
        }

        public static Vector CalculateCrossProduct(Vector a, Vector b)
        {
            return new Vector(
                a.Y * b.Z - a.Z * b.Y,
                a.Z * b.X - a.X * b.Z,
                a.X * b.Y - a.Y * b.X
            );
        }

        public static double CalculateAngleBetween(Vector a, Vector b)
        {
            double dot = CalculateDotProduct(a, b);
            double normProduct = a.CalculateEuclideanNorm() * b.CalculateEuclideanNorm();

            if (normProduct == 0)
                return 0.0;

            double cos = dot / normProduct;
            return Math.Acos(cos) * 180.0 / Math.PI;
        }

        public static bool AreColinear(Vector a, Vector b)
        {
            return CalculateCrossProduct(a, b).IsNullVector();
        }
    }
}
