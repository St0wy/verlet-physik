#pragma once

/**
 * \brief Normalises the provided vector.
 * \tparam T Number type of the vector.
 * \param vec Vector to normalize.
 */
template<typename T>
void normalize(sf::Vector2<T>& vec)
{
	if (vec.x == 0 && vec.y == 0)
		return;

	T length = Magnitude<T>(vec);

	if (length != 0.0)
	{
		vec /= length;
	}
}

/**
 * \brief Gets the magnitude of the vector.
 * \tparam T Number type of the vector.
 * \param vec The vector to get the magnitude from.
 * \return The length of the vector.
 */
template<typename T>
T magnitude(const sf::Vector2<T>& vec)
{
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}