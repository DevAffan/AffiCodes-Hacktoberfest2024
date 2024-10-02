// This is the example of BinarySearchTree (number).
class BSTNode {
    constructor (value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BSTree {
    constructor () {
        this.root = null;
    }

    isEmpty() {
        return this.root === null;
    }

    insert(value) {
        const newNode = new BSTNode(value);

        if (this.isEmpty()) {
            this.root = newNode;
            return newNode;
        }

        return this.insertNode(this.root, newNode);
    }

    insertNode(root, newNode) {
        if (root?.value === newNode.value) {
            return false;
        }

        if (root === null) return false;


        if (root.value > newNode.value) {
            const left = root.left;

            if (left === null) {
                root.left = newNode;
                return newNode;
            }
            
            return this.insertNode(root.left, newNode);
        } else {
            const right = root.right;

            if (right === null) {
                root.right = newNode;
                return newNode;
            }

            return this.insertNode(root.right, newNode);
        }
    }

    search(value, root = this.root) {
        if (root === null) return false;

        if (root.value === value) {
            return true;
        } else if (root.value > value) {
            return this.search(value, root.left);
        } else {
            return this.search(value, root.right);
        }
    }

    min(root = this.root) {
        if (root === null) return false;

        if (root.left === null) {
            return root.value;
        } else {
            return this.min(root.left);
        }
    }

    max(root = this.root) {
        if (root === null) return false;

        if (root.right) {
            return this.max(root.right);
        } else {
            return root.value;
        }
    }

    delete(...value) {
        for (let i = 0; i < value.length; i++) {
            this.root = this.deleteOne(this.root, value[i]);
        }
    }

    deleteOne(root, value) {
        if (root === null) {
            return root;
        }
        
        if (root.value > value) {
            root.left = this.deleteOne(root.left, value);
        } else if (root.value < value) {
            root.right = this.deleteOne(root.right, value);
        } else {
            const left = root.left;
            const right = root.right;

            if (left === null && right === null) {
                return null;
            }

            if (left === null) {
                return root.right;
            }

            if (right === null) {
                return root.left;
            }

            root.value = this.min(root.right);
            root.right = this.deleteOne(root.right, root.value);
        }

        return root;
    }

    breatheFirstSearch(root = this.root) {
        const result = [];
        if (root === null) return result;

        const queue = [];

        queue.push(root);

        while (queue.length) {
            const value = queue.shift();

            result.push(value.value);

            if (value.left) queue.push(value.left);
            if (value.right) queue.push(value.right);
        }

        return result;
    }

    PreOrder(root = this.root) {
        const result = [];
        if (root === null) return result;

        function traverse(rootNode) {
            result.push(rootNode.value);

            if (rootNode.left) traverse(rootNode.left);
            if (rootNode.right) traverse(rootNode.right);
        }

        traverse(root);

        return result;
    }

    inOrder(root = this.root) {
        const result = [];
        if (root === null) return result;

        function traverse(rootNode) {
            if (rootNode.left) traverse(rootNode.left);

            result.push(rootNode.value);

            if (rootNode.right) traverse(rootNode.right);
        }

        traverse(root);

        return result;
    }

    postOrder(root = this.root) {
        const result = [];
        if (root === null) return result;

        function traverse(rootNode) {
            if (rootNode.left) traverse(rootNode.left);
            if (rootNode.right) traverse(rootNode.right);

            result.push(rootNode.value);
        }

        traverse(root);

        return result;
    }
}

module.exports = BSTree;
