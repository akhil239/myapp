class Node():
    def __init__(self,data):
        self.date = data
        self.next = None
class algo():
    
    null = None
    def add_element_at_null(self,data):
        if algo.null is None:
            algo.null = Node(data)
        elif algo.null.next is None:
            algo.null.next = Node(data)
        else:
            current_node = algo.null
            while current_node.next is not None:
                current_node = current_node.next
            else:
                current_node.next = Node(data)
    def print_linked_list(self):
        current_node = algo.null
        while current_node is not None:
            print(current_node.data)
            current_node = current_node.next
        
instance = algo()
instance.add_element_at_null(5)
instance.print_linked_list()



        