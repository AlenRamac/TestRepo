using System;
using System.Collections.Generic;

public interface ICarRepository
{
    IEnumerable<Car> GetAll();
    // Metoda koja prima delegat za filtriranje
    IEnumerable<Car> Filter(Func<Car, bool> predicate);
}