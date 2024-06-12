// Define an enum representing different types of desserts.
enum Dessert {
    // Cake dessert with sweetness as a parameter.
    Cake { sweetness: f64 },
    // Cookie dessert with crunchiness and choco_chips as parameters.
    Cookie { crunchiness: f64, choco_chips: f64 },
}

impl Dessert {
    // Method to calculate the yumminess of the dessert.
    fn yumminess(&self) -> f64 {
        match self {
            // Match on the enum variant to calculate yumminess based on dessert type.
            Dessert::Cake { sweetness } => *sweetness * 1.5,
            Dessert::Cookie { crunchiness, choco_chips } => crunchiness * 2.0 + choco_chips * 3.0,
        }
    }
}

fn print_yumminess(dessert: &Dessert) {
    println!("Yumminess: {}", dessert.yumminess());
}

// Create a vector of desserts containing Cake and Cookie instances.
fn main() {
    let desserts = vec![
        Dessert::Cake { sweetness: 5.0 },
        Dessert::Cookie { crunchiness: 4.0, choco_chips: 6.0 },
    ];

    for dessert in &desserts {
        print_yumminess(dessert);
    }
    
    // Attempt to access memory through the dangling pointer is not possible.
    // Rust's ownership system prevents access to dangling pointers.
}

