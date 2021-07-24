#pragma once

#include <SFML/Graphics.hpp>

//������������ ��������� �����������
enum dirs_en { LEFT, RIGHT, UP, DOWN, NOT_EXIST };
//������������ ���� ��������
enum obj_types {
    BOMBERMAN,
    BOMB,
    WALL_COMMON,
    WALL_UNBREAKABLE,
    FLOOR,
    EXPLOSION,
    MELEE,
    GHOST,
};


class bomb;
class bomb_planter;


//��������� �����������==============================================

//������ ������
const int screen_size_x = 1920,
    screen_size_y = 1080;

//������ ������ ���� � ��������
const int place_size_x = 58,
    place_size_y = 54;


//��������� ����������================================================

//��������� ������ ���������� �� ���������
const std::vector<int> hp_default =
{
    3,      //bomberman
    1,      //bomb
    1,      //wall_common
    100,    //wall_unbreakable
    100,    //floor
    100,    //explosion
    1,      //melee_creep
    1,      //ghost
};


//�������� ������������ ���������� �� ���������
const std::vector<float> move_speed_default =
{
    screen_size_x / 8,      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    screen_size_x / 12,     //melee_creep
    screen_size_x / 16,     //ghost
};


//���� ���������� � ���� �� ���������
const std::vector<int> hand_damage_default =
{
    0,                      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    1, 1,                   //melee_creep - ghost
};


//���� ��������� � ����� �� ���������
const std::vector<int> bomb_damage_default =
{
    1,                      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    0, 0,                   //melee_creep - ghost
};


//������ ������ ����� �� ���������
const std::vector<int> bomb_range_default =
{
    2,                      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    0, 0,                   //melee_creep - ghost
};

//������ �� ������������� ����� �� ���������
const std::vector<float> bomb_timer_default =
{
    3,                      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    0, 0,                   //melee_creep - ghost
};

//�������� ��������� ������������� ����
const std::vector<int> max_bombs_planted_default =
{
    2,                      //bomberman
    0, 0, 0, 0, 0,          //bomb - explosion
    0, 0,                   //melee_creep - ghost
};

//����� �� ��������� ����� ����� �� ���������
const std::vector<bool> wall_pass_default =
{
    false,                                     //bomberman
    false, false, false, false, false,         //bomb - explosion
    false,                                     //melee_creep
    true,                                      //ghost
};


//����� �������� ������� �� ���������
const std::string tex_folder = "textures\\";
//��������� ������� �� ���������
const std::vector<std::string> textures_names =
{
    tex_folder + "bomberman_texture_m.png",         //bomberman
    tex_folder + "bomb_texture.png",                //bomb
    tex_folder + "wall_common_texture.bmp",         //wall_common
    tex_folder + "wall_unbreakable_texture.bmp",    //wall_unbreakable
    tex_folder + "default_texture.bmp",             //floor
    tex_folder + "explosion_texture.png",           //explosion
    tex_folder + "melee_creep_texture.png",         //melee_creep
    tex_folder + "ghost_texture.png",               //ghost
};

const std::string num_tex_folder = tex_folder + "numbers\\";
const const std::vector<std::string> num_textures_names =
{
    num_tex_folder + "texture_0.png",
    num_tex_folder + "texture_1.png",
    num_tex_folder + "texture_2.png",
    num_tex_folder + "texture_3.png",
    num_tex_folder + "texture_4.png",
    num_tex_folder + "texture_5.png",
    num_tex_folder + "texture_6.png",
    num_tex_folder + "texture_7.png",
    num_tex_folder + "texture_8.png",
    num_tex_folder + "texture_9.png"
};



using namespace sf;
//������� ����� ��� ����� ������===========================================
class basic_common
{
protected:
    //������� ���������
    Vector2i position;
    Vector2i logic_pos;

    //������ ��� ��������� ���������
    Sprite sprite;
    Texture texture;
    std::string texture_adress;

    //��� �������
    obj_types obj_type = FLOOR;

    //������� ������ �������
    int lives = 0;

public:
    basic_common()
    {
        
    }
    basic_common(Vector2i pos, obj_types type);
    basic_common(Vector2i pos, std::string tex_adr);
    basic_common(const basic_common &ob);

    Vector2i get_position();
    Vector2i get_log_pos();
    Sprite get_sprite();
    std::string get_tex_adress();
    obj_types get_obj_type();
    int get_lives();

    void set_texture(std::string adress);
    void set_log_pos();
    void set_position(sf::Vector2i pos);

    virtual void hit(int damage);

    virtual int update(float elapsed_time) { return 1; }

    
};


//��������� �������======================================================

//������, ���� ���� � ������ ���� � ������� ������
bool is_only_one_true(std::vector<bool> data);
//������, ���� ���� �� ���� � ������� ������
bool is_any_true(std::vector<bool> data);

//���� ������� ������, �� ������������ ����������� �� ������� �� �������
//���� ������� �� ������, ������������ NOT_EXIST(5)
dirs_en is_neighbours(basic_common* first, basic_common* second);

//�������� ���������� ���������� �� ������� ����, ������� ���������� �� ������
std::vector<sf::Vector2i> logic2screen(std::vector<sf::Vector2i> log_coords);


