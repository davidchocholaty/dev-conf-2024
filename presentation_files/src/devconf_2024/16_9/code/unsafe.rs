fn main() {
    let mut donuts = [1, 2, 3, 4, 5];
    let bart = donuts.as_mut_ptr(); // Bart's pointer to the donuts.

    println!("Ay caramba!");

    unsafe {
        for i in 0..5 { // Bart's prank - doubling the donuts!
            // No bounds checking.
            *bart.add(i) *= 2; // Unsafe pointer arithmetic.
        }
    }

    print!("Uh oh! Bart's modified donuts: ");
    for i in 0..5 {
        print!("{} ", donuts[i]);
    }
    println!("Woo-hoo!");
}