using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LV5.LinearAlgebra
{
    public class Vector
    {
        private double x;
        private double y;
        private double z;

        // Zero vector
        public Vector()
        {
            x = y = z = 0.0;
        }

        // Vector with components
        public Vector(double x, double y, double z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        // Component accessors
        public double X
        {
            get => x;
            set => x = value;
        }

        public double Y
        {
            get => y;
            set => y = value;
        }

        public double Z
        {
            get => z;
            set => z = value;
        }

        public bool IsNullVector()
        {
            return x == 0 && y == 0 && z == 0;
        }

        public double CalculateEuclideanNorm()
        {
            return Math.Sqrt(x * x + y * y + z * z);
        }

        public void MultiplyBy(double scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
        }

        public override string ToString()
        {
            return $"({x}, {y}, {z})";
        }
    }
}
