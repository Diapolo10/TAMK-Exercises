use std::io;
use std::vec::Vec;

fn mass_sum<T>(nums: Vec<T>) -> T {
    let result: T = 0;

    for num in nums {
        result += num;
    }

    return result;
}

fn get_passenger_masses(n: u32 = 4) {
    let masses: Vec<f64> = Vec<f64>::new();

    for num in 1..n { 
        let mut user_input = String::new();
        let input_number: f64 = 0;

        print!("Passenger #{}: ", num);
        io::stdin()
            .read_line(&mut user_input)
            .expect("failed to read from stdin");

        let trimmed = user_input.trim();
        match trimmed.parse::<f64>() {
            Ok(i) => input_number = i,
            Err(..) => println!("this was not an integer: {}", trimmed),
        };

        masses.push(input_number);
    }

    masses
}

fn get_input<T>(prompt: String, base_value: T) -> T {
    let mut user_input = String::new();
    let result: T = base_value;
    print!(prompt);

    io::stdin()
        .read_line(&mut user_input)
        .expect("failed to read from stdin");

    match user_input.trim().parse::<T>() {
        Ok(value) => result = value,
        Err(..) => println!("type conversion failed: {}", user_input)
    };

    result
}

fn main() {
    let max_mass: f64 = .0;
    people: Vec<f64>;
    println!("Hello, world!");
}
