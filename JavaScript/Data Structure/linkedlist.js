// This is the example of SinglyLinkedList (number).

class Node {
    constructor (val) {
        this.value = val;
        this.next = null;
    }
}

class LinkedList {
    constructor () {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    insert(val) {
        const newNode = new Node(val);

        if (this.length === 0) {
            this.head = newNode;
            this.tail = newNode;
            this.length = 1;
            return newNode;
        }

        if (this.tail !== null) {
            this.tail.next = newNode;
            this.tail = newNode;
            this.length++;
        }

        return newNode;
    }

    list() {
        const lists = [];

        let current = this.head;
        while (current) {
            lists.push(current.value);

            current = current.next;
        }

        return lists;
    }
    
    find(val) {
        let found = false;
        let current = this.head;

        while (current) {
            if (current.value.id === val.id) {
                return current;
            }

            current = current.next;
        }

        return found;
    }

    delete(val) {
        if (!this.head) return;

        while (this.head && this.head.value === val) {
            const next = this.head.next;

            if (next) {
                this.head = next;
            } else {
                this.head = null;
                this.tail = null;
                this.len = 0;

                break;
            }
        }

        let current = this.head;
        while (current) {
            const next = current.next;

            if (next && next.value === val) {
                const postNext = next.next;

                if (postNext) {
                    current.next = postNext;
                    this.len--;
                } else {
                    current.next = null;
                    this.tail = current;
                    this.len--;

                    break;
                }
            } else {
                current = current.next;
            }
        }
    }
}

module.exports = LinkedList;