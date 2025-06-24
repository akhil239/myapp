class Node():
    def __init__(self,data):
        self.data = data
        self.next = None

class Linked_list():
    def __init__(self):
        self.root = None

    def add_linked_list(self,data):
        if self.root == None:
            self.root = Node(data)
        else:
            current_node = self.root
            if current_node.next != None:
                current_node = current_node.next
            else:
                current_node.next = Node(data)
    def _print_list(self):
        current_node = self.root
        while current_node != None:
            print(current_node.data)
            current_node = current_node.next

obj = Linked_list()
obj.add_linked_list(5)
obj.add_linked_list(665)
obj._print_list()