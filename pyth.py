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
        count = 0
        while current_node != None:
            count += 1
            print(current_node.data)
            current_node = current_node.next
        return count 
    def add_node_at_front(self,data):
        current_node = self.root
        self.root = Node(data)
        self.root.next = current_node 
        del current_node
    def _length(self):
        current_node = self.root 
        count = 0
        while current_node != None:
            current_node = current_node.next 
            count += 1
        return count
    def add_node_at_middle(self,data):
        middle = self._length()//2
        current_node = self.root
        count = 0
        while count != middle:
            current_node = current_node.next
            count += 1
        else:
            temp = current_node.next 
            current_node.next = Node(data)
            current_node.next.next = temp
            
    def delete_list(self):
        del self.root
        
    def add_node_at_last():
        pass

obj = Linked_list()
obj.add_linked_list(5)
obj.add_linked_list(665)
obj.add_node_at_front(55)
obj.add_node_at_middle(5555)
obj._print_list()