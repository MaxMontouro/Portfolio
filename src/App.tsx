import React, { useState } from 'react';
import { Shield, Terminal, Cpu, Network, Lock, Code, Mail, Github, Linkedin, ChevronDown, ExternalLink, AlertTriangle, Shield as ShieldIcon, Target, User, Briefcase, GraduationCap, Award } from 'lucide-react';
import { Bug } from 'lucide-react';

function App() {
  let bugData = {};  // or assign a proper object structure if needed

  const skills = [
    {
      name: 'Pentest',
      description: 'Simulation d\'attaques contrôlées pour identifier et corriger les vulnérabilités des systèmes'
    },
    {
      name: 'Forensics',
      description: 'Analyse approfondie des systèmes compromis pour investiguer les incidents de sécurité'
    },
    {
      name: 'Reverse Engineering',
      description: 'Analyse détaillée des logiciels et systèmes pour comprendre leur fonctionnement interne'
    },
    {
      name: 'Network Security',
      description: 'Mise en place de défenses pour protéger les infrastructures réseau contre les cyberattaques'
    },
    {
      name: 'OSINT',
      description: 'Techniques de collecte et d\'analyse des informations disponibles publiquement'
    }
  ];

  return (
    <div className="min-h-screen bg-gray-900 text-gray-100">
      {/* Hero Section */}
      <header className="min-h-screen flex flex-col items-center justify-center relative bg-gradient-to-br from-gray-900 via-gray-800 to-gray-900">
        <div className="absolute inset-0 opacity-10">
          {[...Array(50)].map((_, i) => (
            <div
              key={i}
              className="absolute h-1 w-1 bg-green-500 rounded-full"
              style={{
                top: `${Math.random() * 100}%`,
                left: `${Math.random() * 100}%`,
                animation: `pulse ${Math.random() * 3 + 2}s infinite`
              }}
            />
          ))}
        </div>
        <div className="container mx-auto px-4 text-center relative z-10">
          <div className="flex justify-center mb-8">
            <Shield className="w-24 h-24 text-green-500" />
          </div>
          <h1 className="text-5xl md:text-7xl font-bold mb-6 text-transparent bg-clip-text bg-gradient-to-r from-green-400 to-blue-500">
            Étudiant en Cybersécurité
          </h1>
          <p className="text-xl md:text-2xl text-gray-400 mb-8 max-w-2xl mx-auto font-mono">
            &gt; Protéger. Détecter. Répondre.
          </p>
          <div className="flex gap-4 justify-center mb-12">
            <a href="#contact" className="bg-green-600 text-white px-6 py-3 rounded-lg hover:bg-green-700 transition flex items-center gap-2">
              <Terminal className="w-5 h-5" />
              Initier le Contact
            </a>
            <a href="#services" className="border border-green-500 text-green-500 px-6 py-3 rounded-lg hover:bg-green-500 hover:text-white transition flex items-center gap-2">
              <Shield className="w-5 h-5" />
              Services
            </a>
          </div>
        </div>
        <ChevronDown className="absolute bottom-8 animate-bounce w-8 h-8 text-green-500" />
      </header>

      {/* About Section */}
      <section id="about" className="py-20 bg-gray-800">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <User className="w-8 h-8 text-green-500" />
            À Propos
          </h2>
          <div className="grid md:grid-cols-2 gap-12 items-center">
            <div className="space-y-6">
              <div className="relative group">
                <div className="absolute -inset-0.5 bg-gradient-to-r from-green-500 to-blue-500 rounded-lg blur opacity-50 group-hover:opacity-75 transition"></div>
                <img 
                  src="/Portfolio/wrench_portrait.jpg"
                  alt="Photo de profil"
                  className="relative w-full h-[400px] object-cover rounded-lg"
                />
              </div>
              <div className="flex justify-center gap-4">
                <a href="#" className="bg-gray-900 p-3 rounded-lg text-green-500 hover:bg-green-500 hover:text-white transition">
                  <Github className="w-6 h-6" />
                </a>
                <a href="https://fr.linkedin.com/in/maxime-montouro" className="bg-gray-900 p-3 rounded-lg text-green-500 hover:bg-green-500 hover:text-white transition">
                  <Linkedin className="w-6 h-6" />
                </a>
                <a href="#" className="bg-gray-900 p-3 rounded-lg text-green-500 hover:bg-green-500 hover:text-white transition">
                  <Mail className="w-6 h-6" />
                </a>
              </div>
            </div>
            <div className="space-y-8">
              <div>
                <h3 className="text-2xl font-bold mb-4 text-green-400">whoami ?</h3>
                <h4 className="text-xl font-mono text-green-500 mb-2 border-b border-green-500/20 pb-2">Nom de code : Mqks_;</h4>
                <p className="text-gray-300 leading-relaxed">
                  Passionné par la cybersécurité depuis mon plus jeune âge, je suis actuellement étudiant en sécurité informatique. Mon objectif est de protéger les systèmes et les données contre les menaces émergentes tout en contribuant à l'évolution des pratiques de sécurité.
                </p>
              </div>
              <div className="space-y-4">
                <div className="flex items-start gap-4">
                  <Briefcase className="w-6 h-6 text-green-500 mt-1" />
                  <div>
                    <h4 className="font-bold text-lg">Expérience</h4>
                    <p className="text-gray-400">Stage en Sécurité des Systèmes d'Information</p>
                  </div>
                </div>
                <div className="flex items-start gap-4">
                  <GraduationCap className="w-6 h-6 text-green-500 mt-1" />
                  <div>
                    <h4 className="font-bold text-lg">Formation</h4>
                    <p className="text-gray-400"><a href="https://www.2600.eu/">Ecole2600 </a>formation bac+5 (RNCP niveau 7 ) en Cybersécurité</p>
                  </div>
                </div>
                <div className="flex items-start gap-4">
                  <Award className="w-6 h-6 text-green-500 mt-1" />
                  <div>
                    <h4 className="font-bold text-lg">Compétences Clés</h4>
                    <div className="flex flex-wrap gap-2 mt-2">
                      {skills.map((skill) => (
                        <div key={skill.name} className="relative group">
                          <span className="bg-gray-900 px-3 py-1 rounded-full text-sm text-green-400 border border-green-500/20 cursor-help">
                            {skill.name}
                          </span>
                          <div className="absolute bottom-full left-1/2 transform -translate-x-1/2 mb-2 px-4 py-2 bg-gray-900 text-gray-100 text-sm rounded-lg border border-green-500/20 w-64 opacity-0 invisible group-hover:opacity-100 group-hover:visible transition-all duration-200 z-10">
                            <div className="relative">
                              {skill.description}
                              <div className="absolute w-2 h-2 bg-gray-900 border-r border-b border-green-500/20 transform rotate-45 left-1/2 -translate-x-1/2 bottom-[-8px]"></div>
                            </div>
                          </div>
                        </div>
                      ))}
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>

      {/* Services Section */}
      <section id="services" className="py-20 bg-gray-800">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <Shield className="w-8 h-8 text-green-500" />
            Domaines d'Expertise
          </h2>
          <div className="grid md:grid-cols-2 lg:grid-cols-3 gap-8">
            <div className="p-6 bg-gray-900 rounded-lg border border-green-500/20 hover:border-green-500 transition">
              <Network className="w-12 h-12 text-green-500 mb-4" />
              <h3 className="text-xl font-bold mb-2">Tests d'Intrusion</h3>
              <p className="text-gray-400">Évaluation approfondie de la sécurité des systèmes et identification des vulnérabilités.</p>
            </div>
            <div className="p-6 bg-gray-900 rounded-lg border border-green-500/20 hover:border-green-500 transition">
              <AlertTriangle className="w-12 h-12 text-green-500 mb-4" />
              <h3 className="text-xl font-bold mb-2">Reverse Engineering</h3>
              <p className="text-gray-400">Décompilation de programmes binaires et analyse de ces derniers pour détecter des failles.</p>
            </div>
            <div className="p-6 bg-gray-900 rounded-lg border border-green-500/20 hover:border-green-500 transition">
              <Lock className="w-12 h-12 text-green-500 mb-4" />
              <h3 className="text-xl font-bold mb-2">Sécurité Cloud</h3>
              <p className="text-gray-400">Protection des infrastructures cloud et des données sensibles.</p>
            </div>
          </div>
        </div>
      </section>

      {/* Projects Section */}
      <section id="projects" className="py-20 bg-gray-900">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <Bug className="w-8 h-8 text-green-500" />
            Projets de Sécurité
          </h2>
          <div className="grid md:grid-cols-2 lg:grid-cols-3 gap-8">
            {[
              {
                title: "Détection d'Intrusion",
                desc: "Système de détection d'intrusion basé sur l'IA pour la protection des réseaux d'entreprise",
                image: "https://images.unsplash.com/photo-1558494949-ef010cbdcc31?auto=format&fit=crop&q=80&w=500"
              },
              {
                title: "Audit de Sécurité",
                desc: "Framework d'audit automatisé pour l'évaluation de la sécurité des applications web",
                image: "https://images.unsplash.com/photo-1510511459019-5dda7724fd87?auto=format&fit=crop&q=80&w=500"
              },
              {
                title: "Manipulation de données sensibles",
                desc: "Outil de manipulation de données sensibles empêchant toutes attaques possibles, respectant les pratiques de programmation sécurisées",
                image: "https://images.unsplash.com/photo-1614064641938-3bbee52942c7?auto=format&fit=crop&q=80&w=500"
              }
            ].map((project, index) => (
              <div key={index} className="bg-gray-800 rounded-lg overflow-hidden hover:shadow-xl hover:shadow-green-500/10 transition group">
                <img 
                  src={project.image}
                  alt={project.title}
                  className="w-full h-48 object-cover group-hover:scale-105 transition"
                />
                <div className="p-6">
                  <h3 className="text-xl font-bold mb-2 text-green-400">{project.title}</h3>
                  <p className="text-gray-400 mb-4">{project.desc}</p>
                  <div className="flex gap-2">
                    <a href="#" className="text-green-500 hover:text-green-400 flex items-center gap-1">
                      <ExternalLink className="w-4 h-4" />
                      Demo
                    </a>
                    <a href="#" className="text-green-500 hover:text-green-400 flex items-center gap-1">
                      <Github className="w-4 h-4" />
                      Code
                    </a>
                  </div>
                </div>
              </div>
            ))}
          </div>
        </div>
      </section>

      {/* Certifications Section */}
      <section className="py-20 bg-gray-800">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <ShieldIcon className="w-8 h-8 text-green-500" />
            Certifications
          </h2>
          <div className="grid md:grid-cols-2 lg:grid-cols-4 gap-6">
            {[
              { name: "CEH", desc: "Certified Ethical Hacker" },
              { name: "OSCP", desc: "Offensive Security Certified Professional" },
              { name: "CISSP", desc: "Certified Information Systems Security Professional" },
              { name: "CompTIA Security+", desc: "Security+ Certification" }
            ].map((cert, index) => (
              <div key={index} className="p-6 bg-gray-900 rounded-lg border border-green-500/20">
                <h3 className="text-xl font-bold mb-2 text-green-400">{cert.name}</h3>
                <p className="text-gray-400">{cert.desc}</p>
              </div>
            ))}
          </div>
        </div>
      </section>

      {/* Contact Section */}
      <section id="contact" className="py-20 bg-gray-900">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <Terminal className="w-8 h-8 text-green-500" />
            Initier un Contact Sécurisé
          </h2>
          <div className="max-w-xl mx-auto">
            <form 
              className="space-y-6" 
              onSubmit={(e) => {
                e.preventDefault();
                // Ici nous ajouterions la logique d'envoi sécurisé
                alert("Le formulaire est en cours de maintenance pour des raisons de sécurité. Veuillez utiliser les liens de contact directs en bas de page.");
              }}
            >
              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="name" className="block text-sm font-medium text-gray-300 mb-1">
                  Nom_Complet
                </label>
                <input
                  type="text"
                  id="name"
                  required
                  maxLength={100}
                  pattern="^[a-zA-ZÀ-ÿ\s-]{2,100}$"
                  className="w-full px-4 py-2 bg-gray-900 border border-green-500/20 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100"
                  onInvalid={(e) => {
                    e.currentTarget.setCustomValidity('Veuillez entrer un nom valide (lettres, espaces et tirets uniquement)');
                  }}
                  onInput={(e) => {
                    e.currentTarget.setCustomValidity('');
                  }}
                />
              </div>
              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="email" className="block text-sm font-medium text-gray-300 mb-1">
                  Email_Sécurisé
                </label>
                <input
                  type="email"
                  id="email"
                  required
                  maxLength={254}
                  pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$"
                  className="w-full px-4 py-2 bg-gray-900 border border-green-500/20 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100"
                  onInvalid={(e) => {
                    e.currentTarget.setCustomValidity('Veuillez entrer une adresse email valide');
                  }}
                  onInput={(e) => {
                    e.currentTarget.setCustomValidity('');
                  }}
                />
              </div>
              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="message" className="block text-sm font-medium text-gray-300 mb-1">
                  Message_Chiffré
                </label>
                <textarea
                  id="message"
                  required
                  maxLength={1000}
                  rows={4}
                  className="w-full px-4 py-2 bg-gray-900 border border-green-500/20 rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100"
                  onInvalid={(e) => {
                    e.currentTarget.setCustomValidity('Veuillez entrer un message (maximum 1000 caractères)');
                  }}
                  onInput={(e) => {
                    e.currentTarget.setCustomValidity('');
                  }}
                ></textarea>
                <div className="text-sm text-gray-500 mt-2">
                  Caractères restants: <span id="charCount">1000</span>
                </div>
              </div>
              <div className="flex items-center mb-4">
                <input
                  type="checkbox"
                  id="consent"
                  required
                  className="w-4 h-4 text-green-500 bg-gray-900 border-green-500/20 rounded focus:ring-green-500"
                />
                <label htmlFor="consent" className="ml-2 text-sm text-gray-300">
                  Je comprends que ce formulaire est sécurisé mais que les données seront transmises via Internet
                </label>
              </div>
              <button
                type="submit"
                className="w-full bg-green-600 text-white px-6 py-3 rounded-lg hover:bg-green-700 transition flex items-center justify-center gap-2 disabled:opacity-50 disabled:cursor-not-allowed"
              >
                <Lock className="w-5 h-5" />
                Envoyer Message Sécurisé
              </button>
            </form>
          </div>
        </div>
      </section>

      {/* Footer */}
      <footer className="bg-gray-900 text-white py-12 border-t border-green-500/20">
        <div className="container mx-auto px-4">
          <div className="flex flex-col items-center">
            <div className="flex gap-6 mb-8">
              <a href="#" className="text-green-500 hover:text-green-400 transition">
                <Github className="w-6 h-6" />
              </a>
              <a href="https://fr.linkedin.com/in/maxime-montouro" className="text-green-500 hover:text-green-400 transition">
                <Linkedin className="w-6 h-6" />
              </a>
              <a href="#" className="text-green-500 hover:text-green-400 transition">
                <Mail className="w-6 h-6" />
              </a>
              <a 
                href="https://www.root-me.org/" 
                target="_blank" 
                rel="noopener noreferrer" 
                className="text-green-500 hover:text-green-400 transition flex items-center gap-2"
              >
                <Target className="w-6 h-6" />
                <span className="text-sm font-mono">Root-me</span>
              </a>
            </div>
            <p className="text-gray-500 font-mono">
              [root@security ~]# echo "© {new Date().getFullYear()} - Tous droits réservés"
            </p>
          </div>
        </div>
      </footer>
    </div>
  );
}

export default App;
