function Node(element) {
    this.element = element;
    this.next = null;
}

function Stack() {
    var head = null;

    isEmpty = function() {
        if(head==null)
            return true;
        return false;
    }

    push = function(element) {
        var node = new Node(element);
        if(head==null) 
            head = node;
        else {
            var currentNode = head;
            while(currentNode.next) {
                currentNode = currentNode.next;
            }
            currentNode.next = node;
        }
    }

    pop = function() {
        if(!isEmpty()) {
            var currentNode = head;
            var previousNode = null;
            while(currentNode.next) {
                previousNode = currentNode
                currentNode = currentNode.next;
            }
            previousNode.next = null;
            return currentNode.element;
        } else {
            return 'Stack is empty';
        }
    }

    peek = function() {
        var currentNode = head;
        while(currentNode.next) {
            currentNode = currentNode.next;
        }
        return currentNode.element;
    }

    isExist = function(element) {
        var currentNode = head;
        while(currentNode.next) {
            if(element===currentNode.element) {
                return true;
            }
            currentNode = currentNode.next;
        }
        return false;
    }

    display = function() {
        var currentNode = head;
        while(currentNode) {
            console.log(currentNode.element);
            currentNode = currentNode.next;
        }
    }

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    console.log('Stack: ');
    console.log('Displaying stack: ');
    display();
    console.log('Popped element: '+pop());
    console.log('Displaying stack: ');
    display();
    console.log('Peek element: '+peek());
    console.log('Displaying stack: ');
    display();
    if(isExist(3))
        console.log('3 exist in stack');
    else   
        console.log('3 exist not in stack');
    if(isExist(6))
        console.log('6 exist in stack');
    else   
        console.log('6 does not exist in stack');
    
}

Stack();