template <typename T, typename V>
SLLNode<T,V>::SLLNode (const T& key, const V& value) : data(key, value), next(nullptr) {};

template <typename T, typename V>
SLLNode<T,V>::SLLNode (const std::pair<T, V>& pair) : data(pair), next(nullptr) {};