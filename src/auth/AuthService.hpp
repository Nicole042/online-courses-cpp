User registerUser(const std::string& name, const std::string& email,
                  const std::string& password, UserRole role) {
  if (name.size() < 3) throw AuthError("name too short");
  if (!User::isValidEmail(email)) throw AuthError("invalid email format");
  if (password.size() < 4) throw AuthError("password too short");
  auto hash = PasswordHasher::hash(password);
  return repo.create(name, email, hash, role);
}
