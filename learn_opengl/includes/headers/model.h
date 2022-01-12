#pragma once

#include "./shader_m.h"
#include "./mesh.h"

class Model
{
public:
    /*  ����   */
    Model(char* path)
    {
        loadModel(path);
    }
    void Draw(Shader shader);
private:
    /*  ģ������  */
    vector<Mesh> meshes;
    string directory;
    /*  ����   */
    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        string typeName);
};