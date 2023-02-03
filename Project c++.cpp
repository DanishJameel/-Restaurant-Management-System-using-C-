#include <iostream>
#include <vector>
#include <string>

struct Customer {
  std::string name;
  std::string email;
  std::string phone;
};

struct MenuItem {
  std::string name;
  double price;
};

struct Payment {
  std::string email;
  double amount;
};

struct Account {
  std::string email;
  double balance;
};

std::vector<Customer> customers;
std::vector<MenuItem> menu;
std::vector<Payment> payments;
std::vector<Account> accounts;

void addCustomer(const Customer& customer) {
  customers.push_back(customer);
  accounts.push_back({customer.email, 0});
}

void removeCustomer(const std::string& email) {
  for (int i = 0; i < customers.size(); i++) {
    if (customers[i].email == email) {
      customers.erase(customers.begin() + i);
      break;
    }
  }

  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i].email == email) {
      accounts.erase(accounts.begin() + i);
      break;
    }
  }
}

Customer getCustomer(const std::string& email) {
  for (const auto& customer : customers) {
    if (customer.email == email) {
      return customer;
    }
  }

  return Customer{};
}

Account getAccount(const std::string& email) {
  for (const auto& account : accounts) {
    if (account.email == email) {
      return account;
    }
  }

  return Account{};
}

void addPayment(const Payment& payment) {
  payments.push_back(payment);
  for (auto& account : accounts) {
    if (account.email == payment.email) {
      account.balance += payment.amount;
      break;
    }
  }
}

void addMenuItem(const MenuItem& item) {
  menu.push_back(item);
}

void removeMenuItem(const std::string& name) {
  for (int i = 0; i < menu.size(); i++) {
    if (menu[i].name == name) {
      menu.erase(menu.begin() + i);
      break;
    }
  }
}

MenuItem getMenuItem(const std::string& name) {
  for (const auto& item : menu) {
    if (item.name == name) {
      return item;
    }
  }

  return MenuItem{};
}

int main() {
  addCustomer({"John Doe", "johndoe@example.com", "555-555-5555"});
  addCustomer({"Jane Doe", "janedoe@example.com", "555-555-5556"});

  addPayment({"johndoe@example.com", 100});
  addPayment
