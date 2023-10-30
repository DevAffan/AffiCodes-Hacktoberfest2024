type Product = {
    id: number;
    name: string;
    price: number;
    inStock: number;
};

type ProductKeys = keyof Product;

function productAvailability(inStock: number, name: string): void {
    if (inStock > 0) {
        console.log(`Availability of ${name}: ${inStock} in stock`);
    } else {
        console.log(`${name} is out of stock`);
    }
}

type Discount<T> = T & { discountPrice: number };

function hasDiscount<T extends object>(product: T): product is Discount<T> {
    return 'discountPrice' in product;
}

const productWithoutDiscount: Product = {
    id: 1,
    name: "Product A",
    price: 100,
    inStock: 5,
};

const productWithDiscount: Discount<Product> = {
    id: 2,
    name: "Product B",
    price: 150,
    inStock: 0,
    discountPrice: 120,
};

productAvailability(productWithoutDiscount.inStock, productWithoutDiscount.name);
productAvailability(productWithDiscount.inStock, productWithDiscount.name);

if (hasDiscount(productWithDiscount)) {
    console.log(`Discounted price for ${productWithDiscount.name}: ${productWithDiscount.discountPrice}`);
}
