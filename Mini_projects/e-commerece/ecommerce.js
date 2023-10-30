// Step 3: Implement Function to Check Product Availability
function productAvailability(inStock, name) {
    if (inStock > 0) {
        console.log("Availability of ".concat(name, ": ").concat(inStock, " in stock"));
    }
    else {
        console.log("".concat(name, " is out of stock"));
    }
}
// Step 5: Implement Type Predicate for Type Narrowing
function hasDiscount(product) {
    return 'discountPrice' in product;
}
// Step 6: Utilize Sample Products
var productWithoutDiscount = {
    id: 1,
    name: "Product A",
    price: 100,
    inStock: 5,
};
var productWithDiscount = {
    id: 2,
    name: "Product B",
    price: 150,
    inStock: 0,
    discountPrice: 120,
};
// Step 7: Run and Test the Code
productAvailability(productWithoutDiscount.inStock, productWithoutDiscount.name);
productAvailability(productWithDiscount.inStock, productWithDiscount.name);
if (hasDiscount(productWithDiscount)) {
    console.log("Discounted price for ".concat(productWithDiscount.name, ": ").concat(productWithDiscount.discountPrice));
}
