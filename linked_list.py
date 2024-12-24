from platform import node


class Node():
    def __init__(self,data):
        self.data = data
        self.next = None
class D_node():
    def __init__(self,data):
        self.data = data
        self.perent = None
        self.next = None
class algo():
    null = None
    def __init__(self,name):
        self.name = name
        self.read()
    def add_element_at_null(self,data):
        if algo.null is None:
            algo.null = Node(data)
        else:
            current_node = algo.null
            while current_node.next is not None:
                current_node = current_node.next
            else:
                current_node.next = Node(data)
    def print_linked_list(self):
        current_node = algo.null
        while current_node is not None:
            print(current_node.data,end = "<-")
            current_node = current_node.next
    def read(self):
        print("call from __init_")
instance = algo(8)
instance.add_element_at_null(5)
instance.add_element_at_null(10)
instance.add_element_at_null(1006)
instance.add_element_at_null(1006)
instance.add_element_at_null(15600)
instance.add_element_at_null(105740)
instance.add_element_at_null(106440)
instance.add_element_at_null(1040)
instance.print_linked_list()





        