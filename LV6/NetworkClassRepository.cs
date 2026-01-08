using System;
using System.Collections.Generic;
using System.Linq;

public class NetworkCarRepository : ICarRepository
{
    private static List<Car> usedCars = new List<Car>
    {
        new Car("JT2BF28K0X0158222", "Peugeot", "308", 178000, 2011),
        new Car("IFALP5747PA186161", "Volkswagen", "Passat", 129000, 2016),
        new Car("1J4AA2D10AL156565", "Volvo", "V40", 141600, 2016),
        new Car("134FA49502P795977", "Opel", "Insignia", 320395, 2011),
        new Car("IC6RR7MT2DS539778", "Dacia", "Duster", 53509, 2015),
        new Car("2G1FC3D33E9253794", "Porsche", "Panamera", 73000, 2013)
    };

    public IEnumerable<Car> GetAll() => usedCars.AsReadOnly();

    public IEnumerable<Car> Filter(Func<Car, bool> predicate)
    {
        // Koristimo LINQ metodu Where koja interno koristi proslijeđeni delegat
        return usedCars.Where(predicate);
    }
}