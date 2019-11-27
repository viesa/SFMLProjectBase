#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include "Funclib.hpp"

using String = std::string;

class Graphics
{
public:
	enum TextureMapping
	{
		PlayerSpritesheet,
		GrassStandard,
		WaterStandard,
		BeachStandard,
		RockStandard,
		SummerSpritesheet,
		EnumSize
	};

public:
	Graphics(class Camera &camera);
	~Graphics();
	void ClearFrame();
	void EndFrame();

	void Render(const sf::Drawable &drawable);
	void Render(sf::Vector2f point1, sf::Vector2f point2, sf::Color color);
	void Draw(const sf::Drawable &drawable);
	void Draw(class AnimatedSpriteComponent &anim_sc);
	void Draw(class SpriteComponent &sc);
	void Draw(String file_path);
	void Draw(sf::Vector2f point, float raidus = 1.0f, sf::Color color = sf::Color::White);

	void DrawLine(sf::Vector2f point1, sf::Vector2f point2, sf::Color color = sf::Color::White);
	void DrawLine(float x1, float y1, float x2, float y2);

	void ApplyTransformation(sf::Transform add);

	sf::RenderWindow &GetRenderWindow() { return m_window; }
	std::vector<sf::Texture *> allTextures;

private:
	sf::RenderWindow m_window;
	sf::Transform m_transform;

	class Camera &m_camera;

public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};
