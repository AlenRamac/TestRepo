using System;

public class Car : IEquatable<Car>
{
    public string VehicleId { get; private set; }
    public string Make { get; private set; }
    public string Model { get; private set; }
    public int Kilometrage { get; private set; }
    public int BuildYear { get; private set; }

    public Car(string vehicleId, string brand, string type, int kilometrage, int buildYear)
    {
        VehicleId = vehicleId;
        Make = brand;
        Model = type;
        Kilometrage = kilometrage;
        BuildYear = buildYear;
    }

    public override string ToString() => $"{Make} {Model} ({BuildYear}), Km: {Kilometrage}";

    public override int GetHashCode() => HashCode.Combine(VehicleId, Make, Model, BuildYear);

    public override bool Equals(object other)
    {
        Car car = other as Car;
        if (car is null) return false;
        return this.Equals(car);
    }

    public bool Equals(Car other)
    {
        if (other is null) return false;
        return this.Make == other.Make &&
               this.Model == other.Model &&
               this.BuildYear == other.BuildYear &&
               this.Kilometrage == other.Kilometrage;
    }
}