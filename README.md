# 🧾 Simple Billing System – C Project

A beginner-friendly **Billing System** written in C. This program allows users to add items (Tea, Coffee, Burger, Pizza, Sandwich, Cold Drink), generate a full receipt with GST and discounts, accept payment, calculate change, and reset orders.

This is a complete and modular mini-project perfect for C learners.

---

# ⭐ Features

* 🛒 **Add Items** with quantity
* 🧮 **Automatic subtotal calculation**
* 💸 **GST (18%) applied automatically**
* 🎁 **5% discount** on bills above **Rs 1000**
* 📄 **Printable receipt** with item-wise breakdown
* 💰 **Checkout system:** payment input + change/outstanding amount
* 🔄 **Reset order** anytime
* 🧩 Fully modular with functions
* 🛡️ Safe input handling using `read_int()` and `read_double()`

---

# 🧠 How It Works

1. Choose an action from the main menu.
2. Add items from the Items Menu.
3. View the receipt anytime.
4. During checkout:

   * Total = Subtotal + GST − Discount
   * Enter payment → program shows change or outstanding amount.
5. Reset the order or exit.

---

# 🛍️ Items & Prices

| Item       | Price (Rs) |
| ---------- | ---------- |
| Tea        | 10.00      |
| Coffee     | 15.00      |
| Burger     | 60.00      |
| Pizza      | 120.00     |
| Sandwich   | 50.00      |
| Cold Drink | 25.00      |

---

# 🧪 Sample Output

```
=== Simple Billing System ===

Main Menu:
1. Add Item
2. Show Receipt
3. Checkout / Pay
4. Reset Order
5. Exit
Enter choice: 1

Items Menu:
1. Tea        - Rs 10.00
2. Coffee     - Rs 15.00
3. Burger     - Rs 60.00
4. Pizza      - Rs 120.00
5. Sandwich   - Rs 50.00
6. Cold Drink - Rs 25.00
0. Cancel
Choose item number (0 to cancel): 4
Enter quantity: 2
Added 2 of item 4 to the order.
```

### Receipt Example

```
===== RECEIPT =====
Item        Qty   Amount
-------------------------------
Pizza       2     240.00
Cold Drink  3     75.00
-------------------------------
Subtotal:          315.00
GST (18%):         56.70
Grand Total:       371.70
===============================
```

---

# ▶️ Compile & Run

### Windows

```
gcc billing.c -o billing.exe
billing.exe
```

### Linux / macOS

```
gcc billing.c -o billing
./billing
```

---

# 📂 File Included

* `billing.c` (full program source code)

---

# 👨‍💻 Author

Created by **Deepak Rakshit** as part of learning real-world C programming and structured design.
