from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Mock product data
products = [
    {"id": 1, "name": "Laptop", "price": 999.99, "description": "A high-performance laptop."},
    {"id": 2, "name": "Headphones", "price": 199.99, "description": "Noise-canceling headphones."},
    {"id": 3, "name": "Smartphone", "price": 699.99, "description": "A latest-generation smartphone."},
]

@app.route('/')
def homepage():
    return render_template('index.html', products=products)

@app.route('/product/<int:product_id>')
def product_page(product_id):
    product = next((p for p in products if p["id"] == product_id), None)
    return render_template('product.html', product=product)

if __name__ == '__main__':
    app.run(debug=True)
