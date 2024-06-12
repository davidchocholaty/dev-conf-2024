fn add_beer(beers: &mut Vec<i32>) {
    beers.push(10);  // Safe, Rust's Vec handles resizing.
}

fn main() {
    let beer_fridge = vec![0; 5]; // A new fridge.
    drop(beer_fridge); // Throw it away!

    // println!("{}", beer_fridge[0]);  // Leads to compile-time error.

    let mut beer_collection = vec![0; 5];
    add_beer(&mut beer_collection); // Rust's borrowing.

    let lost_beer = Box::new(42); // Special beer.
    // Automatically deallocated when it goes out of scope.

    // No manual management needed.
}