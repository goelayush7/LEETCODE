SELECT Product.product_name, sales.year ,sales.price from sales join Product on
sales.product_id=product.product_id