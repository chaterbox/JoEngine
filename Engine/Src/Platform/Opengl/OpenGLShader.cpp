#include "Joepch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "Joe/Renderer/RendererAPI.h"

namespace Joe{
	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc){
		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL){
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

			const GLchar* source = vertexSrc.c_str();
			glShaderSource(vertexShader, 1, &source, 0);

			glCompileShader(vertexShader);

			GLint isCompiled = 0;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled = GL_FALSE){
				GLint maxLength = 0;
				glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(vertexShader);

				JOE_CORE_ERROR("{0}", infoLog.data());
				JOE_CORE_ASSERT(false, "vertex shader compile error:")

				return;
			}

			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

			source = fragmentSrc.c_str();
			glShaderSource(fragmentShader, 1, &source, 0);

			glCompileShader(fragmentShader);

			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled == GL_FALSE){
				GLint maxLength = 0;
				glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(fragmentShader);
				glDeleteShader(vertexShader);

				JOE_CORE_ERROR("{0}", infoLog.data());
				JOE_CORE_ASSERT(false, "fragment shader compile error:")

				return;
			}
			m_RendererID = glCreateProgram();
			GLuint program = m_RendererID;

			glAttachShader(program, vertexShader);
			glAttachShader(program, fragmentShader);

			glLinkProgram(program);

			GLint isLinked = 0;
			glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);

			if (isLinked == GL_FALSE){
				GLint maxLength = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar>infoLog(maxLength);
				glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

				glDeleteProgram(program);

				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);

				JOE_CORE_ERROR("{0}", infoLog.data());
				JOE_CORE_ASSERT(false, "shader program linking error:")

				return;
			}
			glDetachShader(program, vertexShader);
			glDetachShader(program, fragmentShader);
		}
	}

	OpenGLShader::~OpenGLShader(){
		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL){
			glDeleteProgram(m_RendererID);
		}
	}

	void OpenGLShader::Bind() const{
		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL){
			glUseProgram(m_RendererID);
		}
	}

	void OpenGLShader::Unbind() const{
		glUseProgram(0);
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix){
		GLint Location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(Location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}
