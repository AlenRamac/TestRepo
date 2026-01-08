using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        ICarRepository repository = new NetworkCarRepository();

        // --- PRVI SLUČAJ: Filtriranje po kilometraži ---
        Console.WriteLine("--- Filtriranje po rasponu kilometara ---");
        Console.Write("Unesite minimalnu kilometražu: ");
        int minKm = int.Parse(Console.ReadLine());
        Console.Write("Unesite maksimalnu kilometražu: ");
        int maxKm = int.Parse(Console.ReadLine());

        // Lambda izraz za provjeru raspona
        var filteredByKm = repository.Filter(c => c.Kilometrage >= minKm && c.Kilometrage <= maxKm);

        Console.WriteLine("Rezultati:");
        DisplayCars(filteredByKm);

        // --- DRUGI SLUČAJ: Filtriranje po proizvođaču ---
        Console.WriteLine("\n--- Filtriranje po imenu proizvođača ---");
        Console.Write("Unesite ime proizvođača (npr. volkswagen): ");
        string inputMake = Console.ReadLine();

        // Lambda izraz koji ignorira velika/mala slova
        var filteredByMake = repository.Filter(c =>
            c.Make.Equals(inputMake, StringComparison.OrdinalIgnoreCase));

        Console.WriteLine("Rezultati:");
        DisplayCars(filteredByMake);
    }

    static void DisplayCars(IEnumerable<Car> cars)
    {
        foreach (var car in cars)
        {
            Console.WriteLine(car.ToString());
        }
    }
}