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