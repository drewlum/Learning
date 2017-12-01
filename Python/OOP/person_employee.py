# Base or Super class


def is_employee():
    return False


class Person(object):
    def __init__(self, name):
        self.name = name
        
    def get_name(self):
        return self.name


# Inherited or Subclass (Note Person in bracket)
class Employee(Person):
    
    def __init__(self, name, eid):
        super(Employee, self).__init__(name)
        self.empID = eid

    def is_employee(self):
        return True
        
    def get_id(self):
        return self.empID


# Driver code
emp = Employee("Geek1", "E101") 
emp2 = Employee("Person", "E102")
print(emp.get_name(), emp.is_employee(), emp.get_id())
print(emp2.get_name(), emp2.is_employee(), emp2.get_id())
