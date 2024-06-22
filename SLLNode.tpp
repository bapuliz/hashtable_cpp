template <typename K, typename V>
SLLNode<K,V>::SLLNode (const K& key, const V& value) : data(key, value), next(nullptr) {};

template <typename K, typename V>
SLLNode<K,V>::SLLNode (const std::pair<K, V>& pair) : data(pair), next(nullptr) {};