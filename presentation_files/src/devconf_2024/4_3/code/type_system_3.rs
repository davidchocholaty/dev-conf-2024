// Create a vector of desserts containing Cake and Cookie instances.
fn main() {
    let desserts = vec![
        Dessert::Cake { sweetness: 5.0 },
        Dessert::Cookie { crunchiness: 4.0, choco_chips: 6.0 },
    ];

    // ...

    // Rust's ownership system prevents access to dangling pointers.
}