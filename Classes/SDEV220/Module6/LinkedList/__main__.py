"""
Jeffrey Harmon
SDEV220
LinkedList.py
May. 2, 2021
"""

from LinkedList import LinkedList

list1 = LinkedList({"Tom", "George", "Peter", "Jean", "Jane"})
list2 = LinkedList({"Tom", "George", "Michael", "Michelle", "Daniel"})


print(f"list1:\n{list1}\n")
print(f"list2:\n{list2}\n")


list1.addAll(list2)
print(f"Add:\n{list1}\n")

list1.removeAll(list2)
print(f"Remove:\n{list1}\n")

list1.retainAll(list2)
print(f"Retain:\n{list1}")
