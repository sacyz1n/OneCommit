#pragma once

enum NodeType : unsigned short
{
	Left, Right, End
};

enum TraservalType : unsigned short
{
	PreOrder, InOrder, PostOrder
};

template <typename T>
struct BinTreeNode
{
	T data;
	NodeType nodeType;
	BinTreeNode* childNode[NodeType::End];
	BinTreeNode* parentNode = nullptr;

	BinTreeNode(const T& _data, BinTreeNode* _parentNode = nullptr, NodeType _nodeType = NodeType::End)
		: data(_data)
		, parentNode(_parentNode)
		, nodeType(_nodeType)
	{
		for (unsigned short i = 0; i < NodeType::End; ++i)
			childNode[i] = nullptr;
	}
};

template <typename T>
class CBinaryTree
{
public:
	explicit CBinaryTree();
	~CBinaryTree();

private:
	unsigned int    mSize = 0;
	BinTreeNode<T>* mRootNode = nullptr;

private:
	void erase(BinTreeNode<T>* _node);
	void PreOrderTraversal(BinTreeNode<T>* _node); // 전위 순회
	void InOrderTraversal(BinTreeNode<T>* _node);  // 중위 순회
	void PostOrderTraversal(BinTreeNode<T>* _node); // 후위 순회

public:
	BinTreeNode<T>*    insert(const T& _data);
	BinTreeNode<T>*    insert(BinTreeNode<T>* _parentNode, NodeType _nodeType, const T& _data);
	BinTreeNode<T>*    GetNode(BinTreeNode<T>* _parentNode = nullptr, NodeType _nodeType = NodeType::End);
	const unsigned int size() const;
	void TraservalNode(TraservalType _traservalType);
};

template<typename T>
inline CBinaryTree<T>::CBinaryTree()
{
}

template<typename T>
inline CBinaryTree<T>::~CBinaryTree()
{
	erase(mRootNode);
}

template<typename T>
inline void CBinaryTree<T>::erase(BinTreeNode<T>* _node)
{
	if (nullptr == _node)
		return;

	erase(_node->childNode[NodeType::Left]);
	erase(_node->childNode[NodeType::Right]);

	if (nullptr != _node->parentNode)
		_node->parentNode->childNode[_node->nodeType] = nullptr;
	else
		mRootNode = nullptr;

	delete _node;
}

template<typename T>
inline void CBinaryTree<T>::PreOrderTraversal(BinTreeNode<T>* _node)
{
}

template<typename T>
inline void CBinaryTree<T>::InOrderTraversal(BinTreeNode<T>* _node)
{
}

template<typename T>
inline void CBinaryTree<T>::PostOrderTraversal(BinTreeNode<T>* _node)
{
}

template<typename T>
inline BinTreeNode<T>* CBinaryTree<T>::insert(const T & _data)
{
	if (nullptr != mRootNode)
		return nullptr;

	mRootNode = new BinTreeNode<T>(_data);
	++mSize;

	return mRootNode;
}

template<typename T>
inline BinTreeNode<T>* CBinaryTree<T>::insert(BinTreeNode<T>* _parentNode, NodeType _nodeType, const T & _data)
{
	if (_parentNode == nullptr || _parentNode->childNode[_nodeType] != nullptr)
		return nullptr;

	BinTreeNode<T>* newNode = new BinTreeNode<T>(_data, _parentNode, _nodeType);
	_parentNode->childNode[_nodeType] = newNode;
	++mSize;

	return newNode;
}

template<typename T>
inline const unsigned int CBinaryTree<T>::size() const
{
	return mSize;
}

template<typename T>
inline void CBinaryTree<T>::TraservalNode(TraservalType _traservalType)
{
	switch (_traservalType)
	{
	case PreOrder:
		PreOrderTraversal(mRootNode);
		break;
	case InOrder:
		InOrderTraversal(mRootNode);
		break;
	case PostOrder:
		PostOrderTraversal(mRootNode);
		break;
	}
}

template<typename T>
inline BinTreeNode<T>* CBinaryTree<T>::GetNode(BinTreeNode<T>* _parentNode, NodeType _nodeType)
{
	if (_parentNode == nullptr || _nodeType == NodeType::End)
		return mRootNode;

	return _parentNode->childNode[_nodeType];
}

